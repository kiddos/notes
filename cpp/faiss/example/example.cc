#include <faiss/IndexFlat.h>

#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

int main(void) {
  int d = 64;      // vector Dimension
  int nb = 10000;  // Number of database vectors
  int nq = 5;      // Number of query vectors
  int k = 4;       // Number of nearest neighbors to find

  // Generate random database vectors (xb)
  std::vector<float> xb(d * nb);
  std::mt19937 rng;
  std::uniform_real_distribution<> distrib;
  for (int i = 0; i < nb; i++) {
    for (int j = 0; j < d; j++) xb[d * i + j] = distrib(rng);
    xb[d * i] += i / 1000.;  // Add a small offset to make vectors distinct
  }

  // Generate random query vectors (xq)
  std::vector<float> xq(d * nq);
  for (int i = 0; i < nq; i++) {
    for (int j = 0; j < d; j++) xq[d * i + j] = distrib(rng);
    xq[d * i] += i / 1000.;
  }

  // IndexFlatL2 is for exact L2 (Euclidean) distance search
  faiss::IndexFlatL2 index(d);

  index.add(nb, xb.data());
  std::cout << "Index ntotal = " << index.ntotal << std::endl;

  // Search for the k-nearest neighbors
  std::vector<faiss::idx_t> I(k * nq);  // To store indices of neighbors
  std::vector<float> D(k * nq);         // To store distances

  index.search(nq, xq.data(), k, D.data(), I.data());

  std::cout << "Search results (indices of top-" << k << " neighbors):" << std::endl;
  for (int i = 0; i < nq; i++) {
    std::cout << "Query " << i << ": ";
    for (int j = 0; j < k; j++) {
      std::cout << std::setw(5) << I[i * k + j];
    }
    std::cout << std::endl;
  }

  return 0;
}
