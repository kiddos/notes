#include <g2o/core/base_unary_edge.h>
#include <g2o/core/base_vertex.h>

class Vertex1D : public g2o::BaseVertex<1, double> {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

  // Set the initial value (estimate)
  virtual void setToOriginImpl() override { _estimate = 0.0; }

  // Read/Write is usually for file I/O, not strictly needed for a simple
  // example.
  virtual bool read(std::istream& is) override { return true; }
  virtual bool write(std::ostream& os) const override { return true; }

  // Update the estimate based on the computed gradient/update vector (dx)
  virtual void oplusImpl(const double* update) override {
    _estimate += update[0];
  }
};

class Edge1D : public g2o::BaseUnaryEdge<1, double, Vertex1D> {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW;

  // Compute the error/residual vector
  virtual void computeError() override {
    const Vertex1D* v = static_cast<const Vertex1D*>(_vertices[0]);
    double x = v->estimate();
    double measurement = _measurement;  // The observed value z_i

    // Error = Measurement - Estimate (z_i - x)
    _error[0] = measurement - x;
  }

  // Compute the Jacobian (df/dx). For e = z - x, df/dx is -1.
  // g2o often uses numerical differentiation, but providing a closed form is
  // faster and more stable.
  virtual void linearizeOplus() override {
    // The Jacobian is the derivative of the error w.r.t the vertex estimate.
    // J[0] corresponds to the derivative w.r.t the single variable of Vertex1D.
    _jacobianOplusXi(0, 0) = -1.0;
  }

  // Read/Write implementation (not necessary for this example)
  virtual bool read(std::istream& is) override { return true; }
  virtual bool write(std::ostream& os) const override { return true; }
};
