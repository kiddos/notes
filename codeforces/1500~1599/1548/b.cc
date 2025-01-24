#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> d(n);
  for (int i = 1; i < n; ++i) {
    d[i] = abs(a[i-1] - a[i]);
  }

  int L = ceil(log2(n)) + 1;
  vector<vector<i64>> sparse_table(L, vector<i64>(n));
  sparse_table[0] = d;
  for (int l = 1; l < L; ++l) {
    for (int i = 1; i <= n-(1<<l); ++i) {
      sparse_table[l][i] = gcd(sparse_table[l-1][i], sparse_table[l-1][i + (1<<(l-1))]);
    }
  }

  auto log_floor = [&](int len) -> int {
    return __builtin_clz(1) - __builtin_clz(len);
  };

  auto query_gcd = [&](int l, int r) -> i64 {
    int len = r-l + 1;
    int k = log_floor(len);
    return gcd(sparse_table[k][l], sparse_table[k][r-(1<<k)+1]);
  };

  int ans = 1;
  for (int i = 1; i < n; ++i) {
    int l = i, r = n-1;
    int index = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 g = query_gcd(i, mid);
      if (g > 1) {
        index = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    if (index >= 0) {
      int longest = index-i+1;
      // cout << "i=" << i << ", index=" << index << endl;
      ans = max(ans, longest+1);
    }
  }
  cout << ans << endl;
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
