#include "directed_edge_orientations.h"

template <typename DerivedC, typename DerivedE>
IGL_INLINE void igl::directed_edge_orientations(
  const Eigen::PlainObjectBase<DerivedC> & C,
  const Eigen::PlainObjectBase<DerivedE> & E,
  std::vector<
      Eigen::Quaterniond,Eigen::aligned_allocator<Eigen::Quaterniond> > & Q)
{
  using namespace Eigen;
  Q.resize(E.rows());
  for(int e = 0;e<E.rows();e++)
  {
    const auto & b = C.row(E(e,1)) - C.row(E(e,0));
    Q[e].setFromTwoVectors( RowVector3d(1,0,0),b);
  }
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instanciation
template void igl::directed_edge_orientations<Eigen::Matrix<double, -1, -1, 0, -1, -1>, Eigen::Matrix<int, -1, -1, 0, -1, -1> >(Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&, std::vector<Eigen::Quaternion<double, 0>, Eigen::aligned_allocator<Eigen::Quaternion<double, 0> > >&);
#endif