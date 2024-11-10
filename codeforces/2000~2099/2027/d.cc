#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(m+1);
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }

  vector<i64> p = a;
  for (int i = 1; i <= n; ++i) {
    p[i] += p[i-1];
  }

  constexpr int inf = 1e9;
  vector<int> dp(n+1, inf);
  dp[0] = 0;
  for (int k = 1; k <= m; ++k) {
    for (int i = 1; i <= n; ++i) {
      int l = 0, r = i;
      int idx = -1;
      while (l <= r) {
        int mid = l + (r-l) / 2;
        i64 prefix = p[i] - p[mid];
        if (prefix <= b[k]) {
          idx = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }

      if (idx >= 0) {
        dp[i] = min(dp[i], dp[idx] + m-k);
      }
    }

    // for (int i = 0; i <= n; ++i) {
    //   cout << dp[i] << " ";
    // }
    // cout << endl;
  }


  int ans = dp[n];
  if (ans >= inf) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
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
