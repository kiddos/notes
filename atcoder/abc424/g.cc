#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(m);
  vector<i64> c(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i] >> c[i];
  }

  vector<pair<int,i64>> songs;
  for (int i = 0; i < m; ++i) {
    songs.push_back({b[i], c[i]});
  }
  sort(songs.rbegin(), songs.rend());

  vector<i64> possible(m+1);
  for (int k = 1; k <= m; ++k) {
    for (int i = 0; i < n; ++i) {
      possible[k] += min(a[i], k);
    }
  }

  vector<map<int,i64>> dp(m+1);
  dp[0][0] = 0;
  for (int i = 0; i < m; ++i) {
    vector<map<int,i64>> dp2 = dp;
    for (int selected = 0; selected <= i; ++selected) {
      for (auto [bsum, excite] : dp[selected]) {
        int bsum2 = bsum + songs[i].first;
        if (possible[selected+1] >= bsum2) {
          dp2[selected+1][bsum2] = max(dp2[selected+1][bsum2], excite + songs[i].second);
        }
      }
    }
    dp = std::move(dp2);
  }

  i64 ans = 0;
  for (int selected = 1; selected <= m; ++selected) {
    for (auto [bsum, excite] : dp[selected]) {
      ans = max(ans, excite);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
