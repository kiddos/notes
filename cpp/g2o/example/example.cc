#include <g2o/core/block_solver.h>
#include <g2o/core/optimization_algorithm_levenberg.h>
#include <g2o/core/sparse_optimizer.h>
#include <g2o/solvers/eigen/linear_solver_eigen.h>

#include <iostream>
#include <memory>

#include "sample_types.h"

using BlockSolverType =
    g2o::BlockSolver<g2o::BlockSolverTraits<1, 1>>;  // <dim_vertex, dim_edge>
using LinearSolverType =
    g2o::LinearSolverEigen<BlockSolverType::PoseMatrixType>;

int main() {
  // Instantiate the linear solver and block solver
  g2o::OptimizationAlgorithmLevenberg* solver =
      new g2o::OptimizationAlgorithmLevenberg(std::make_unique<BlockSolverType>(
          std::make_unique<LinearSolverType>()));

  // Instantiate the Sparse Optimizer
  g2o::SparseOptimizer optimizer;
  optimizer.setAlgorithm(solver);
  optimizer.setVerbose(true);

  Vertex1D* v_x = new Vertex1D();
  v_x->setId(0);
  // Give it a poor initial guess (true value is 5.0)
  v_x->setEstimate(10.0);
  optimizer.addVertex(v_x);

  std::vector<double> measurements = {4.9, 5.1, 4.8, 5.2,
                                      5.0, 5.3};  // Observations around 5.0
  double information_value = 1.0;

  for (size_t i = 0; i < measurements.size(); ++i) {
    Edge1D* edge = new Edge1D();
    edge->setId(i);

    // Connect the edge to the vertex
    edge->setVertex(0, v_x);

    // Set the measurement (the 'z_i' in e = z_i - x)
    edge->setMeasurement(measurements[i]);

    // Set the information matrix (a scalar in 1D)
    edge->setInformation(Eigen::Matrix<double, 1, 1>::Identity() *
                         information_value);

    optimizer.addEdge(edge);
  }

  // Perform Optimization
  std::cout << "\nStarting Optimization..." << std::endl;
  optimizer.initializeOptimization();
  optimizer.optimize(10);

  std::cout << "\n--- Optimization Result ---" << std::endl;
  std::cout << "Initial estimate was: 10.0" << std::endl;
  std::cout << "Optimized estimate for X: " << v_x->estimate() << std::endl;

  // The true mean of the measurements is (4.9+5.1+4.8+5.2+5.0+5.3) / 6 = 5.05
  return 0;
}
