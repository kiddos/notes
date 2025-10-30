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
  vector<i64> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  vector<i64> vals = a;
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  int m = vals.size();

  vector<i64> dp(m), prev(m);
  for (int j = 0; j < m; ++j) {
    prev[j] = (a[0] == vals[j] ? 0 : c[0]);
  }

  for (int i = 1; i < n; ++i) {
    vector<i64> prefix(m);
    prefix[0] = prev[0];
    for (int j = 1; j < m; ++j) {
      prefix[j] = min(prefix[j - 1], prev[j]);
    }

    for (int j = 0; j < m; ++j) {
      i64 cost = (a[i] == vals[j] ? 0 : c[i]);
      dp[j] = cost + prefix[j];
    }
    prev.swap(dp);
  }

  i64 ans = *min_element(prev.begin(), prev.end());
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
