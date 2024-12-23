#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> queries(q);
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    queries[i] = {l-1, r-1};
  }

  vector<int> d;
  for (int i = 0; i+1 < n; ++i) {
    d.push_back(abs(a[i+1] - a[i]));
  }

  int size = d.size();
  int L = ceil(log2(size));
  L = max(L, 3);
  vector<vector<int>> sparse_table(L+1, vector<int>(size));
  sparse_table[0] = d;
  for (int p = 1; p <= L; ++p) {
    int p2 = 1<<p, p1 = (1<<(p-1));
    for (int i = 0; i <= size-p2; ++i) {
      sparse_table[p][i] = gcd(sparse_table[p-1][i], sparse_table[p-1][i+p1]);
    }
  }

  // for (int i = 0; i <= L; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     cout << sparse_table[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  auto log_floor = [&](int len) -> int {
    return __builtin_clzll(1) - __builtin_clzll(len);
  };

  auto get_gcd = [&](int l, int r) -> int {
    if (l == r) {
      return 0;
    }
    r--;
    int len = r - l + 1;
    int f = log_floor(len);
    return gcd(sparse_table[f][l], sparse_table[f][r-(1<<f)+1]);
  };

  for (auto [l, r] : queries) {
    int ans = get_gcd(l, r);
    cout << ans << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
