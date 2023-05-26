#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, s = 0;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<pair<ll,ll>> pairs;
  for (int i = 0; i < n; ++i) {
    if (s > a[i]) {
      pairs.push_back({0, a[i]});
    } else {
      ll p = a[i] - s;
      ll q = a[i] - p;
      pairs.push_back({min(p, q), max(p, q)});
    }
  }

  pairs[0] = {a[0], a[0]};
  pairs.back() = {a.back(), a.back()};

  // cout << "pairs: ";
  // for (auto [p, q] : pairs) cout << p << "," << q << "  ";
  // cout << endl;

  vector<ll> dp(2);
  for (int i = 1; i < n; ++i) {
    vector<ll> next_dp(2);
    next_dp[0] = min(
        dp[0] + pairs[i-1].second * pairs[i].first,
        dp[1] + pairs[i-1].first * pairs[i].first);
    next_dp[1] = min(
        dp[0] + pairs[i-1].second * pairs[i].second,
        dp[1] + pairs[i-1].first * pairs[i].second);
    dp = move(next_dp);
  }
  ll ans = min(dp[0], dp[1]);
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
