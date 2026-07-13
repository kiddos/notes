#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int MAX_N = 2000;

vector<int> primes;

void precompute() {
  vector<bool> is_prime(MAX_N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p * p <= MAX_N; p++) {
    if (is_prime[p]) {
      for (int i = p + p; i <= MAX_N; i += p) {
          is_prime[i] = false;
      }
    }
  }
  for (int p = 2; p <= MAX_N; p++) {
    if (is_prime[p]) {
      primes.push_back(p);
    }
  }

  // for (int i = 2; i <= 1000; ++i) {
  //   auto it = lower_bound(primes.begin(), primes.end(), i);
  //   cout << "i=" << i << ", next larger prime = " << *it << endl;
  // }
}

void solve() {
  int n = 0;
  cin >> n;

  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    edges.push_back({i, i+1});
  }
  edges.push_back({n, 1});
  int p = *lower_bound(primes.begin(), primes.end(), n);
  int missing_edges = p - n;

  for (int i = 1; i < n && missing_edges > 0; i += 4) {
    if (missing_edges) {
      edges.push_back({i, i+2});
      missing_edges--;
    }
    if (missing_edges) {
      edges.push_back({i+1, i+3});
      missing_edges--;
    }
  }

  cout << edges.size() << endl;
  for (auto [u, v] : edges) {
    cout << u << " " << v << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();
  solve();
  return 0;
}
