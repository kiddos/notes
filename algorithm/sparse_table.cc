#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
  vector<int> a;
  int n = 16;
  for (int i = 0; i < n; ++i) {
    a.push_back(gen() % 32);
  }

  auto f = [&](int x, int y) -> int {
    return min(x, y);
  };

  int L = ceil(log2(n));
  vector<vector<int>> sparse_table(L+1, vector<int>(n));
  sparse_table[0] = a;
  for (int p = 1; p <= L; ++p) {
    for (int i = 0; i <= n-(1<<p); ++i) {
      sparse_table[p][i] = f(sparse_table[p-1][i], sparse_table[p-1][i+(1<<(p-1))]);
    }
  }

  auto log_floor = [&](int len) -> int {
    return __builtin_clzll(1) - __builtin_clzll(len);
  };

  auto get_minimum = [&](int l, int r) -> int {
    int len = r - l + 1;
    int k = log_floor(len);
    return f(sparse_table[k][l], sparse_table[k][r-(1<<k)+1]);
  };

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;

  vector<pair<int,int>> queries = {{0, 4}, {2, 6}, {0, 15}, {3, 9}, {7, 11}};
  for (auto& [l, r] : queries) {
    int brute_force = a[l];
    for (int i = l; i <= r; ++i) {
      brute_force = f(brute_force, a[i]);
    }

    int result = get_minimum(l, r);
    assert(result == brute_force);
    cout << "l~r: f(" << l << "," << r << ")=" << result << endl;
  }
  return 0;
}
