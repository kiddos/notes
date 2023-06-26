#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll MIN_VAL = numeric_limits<int>::min();

void solve() {
  string s;
  cin >> s;

  vector<vector<ll>> dp(5, vector<ll>(2, MIN_VAL));
  vector<ll> values = {1, 10, 100, 1000, 10000};
  dp[0][0] = 0;

  int n = s.length();
  for (int i = n-1; i >= 0; --i) {
    vector<vector<ll>> next_dp(5, vector<ll>(2, MIN_VAL));

    int c = s[i] - 'A';
    for (int c1 = 0; c1 < 5; ++c1) {
      for (int c2 = 0; c2 < 5; ++c2) {
        for (int k = 0; k < 2; ++k) {
          int max_c = max(c2, c1);
          int k2 = k + (c2 != c);
          ll val = c2 < max_c ? - values[c2] : values[c2];
          if (k2 < 2) {
            next_dp[max_c][k2] = max(next_dp[max_c][k2], dp[c1][k] + val);
          }
        }
      }
    }

    dp = move(next_dp);
  }

  ll ans = MIN_VAL;
  for (int c = 0; c < 5; ++c) {
    for (int k = 0; k < 2; ++k) {
      ans = max(ans, dp[c][k]);
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
