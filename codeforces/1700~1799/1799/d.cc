#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<ll> cold(k+1);
  for (int i = 1; i <= k; ++i) cin >> cold[i];

  vector<ll> hot(k+1);
  for (int i = 1; i <= k; ++i) cin >> hot[i];

  // vector<vector<vector<ll>>> memo(n, vector<vector<ll>>(k+1, vector<ll>(k+1)));
  // function<ll(int,int,int)> dp = [&](int i, int a1, int a2) -> ll {
  //   if (i == n) return 0LL;
  //   if (memo[i][a1][a2]) return memo[i][a1][a2];
  //   ll ans = min(dp(i+1, a[i], a2) + (a1 == a[i] ? hot[a[i]] : cold[a[i]]),
  //                dp(i+1, a1, a[i]) + (a2 == a[i] ? hot[a[i]] : cold[a[i]]));
  //   return memo[i][a1][a2] = ans;
  // };

  // ll ans = dp(0, 0, 0);

  // const ll INF = 1e16;
  // vector<vector<ll>> dp(k+1, vector<ll>(k+1, INF));
  // dp[0][0] = 0;
  // for (int i = 0; i < n; ++i) {
  //   vector<vector<ll>> dp2(k+1, vector<ll>(k+1, INF));
  //   for (int a1 = 0; a1 <= k; ++a1) {
  //     for (int a2 = 0; a2 <= k; ++a2) {
  //       ll t1 = a1 == a[i] ? hot[a[i]] : cold[a[i]];
  //       dp2[a[i]][a2] = min(dp2[a[i]][a2], dp[a1][a2] + t1);
  //       ll t2 = a2 == a[i] ? hot[a[i]] : cold[a[i]];
  //       dp2[a1][a[i]] = min(dp2[a1][a[i]], dp[a1][a2] + t2);
  //     }
  //   }
  //   dp = move(dp2);
  // }

  // ll ans = numeric_limits<ll>::max();
  // for (int a1 = 0; a1 <= k; ++a1) {
  //   for (int a2 = 0; a2 <= k; ++a2) {
  //     ans = min(ans, dp[a1][a2]);
  //   }
  // }

  const ll INF = 1e16;
  vector<ll> dp(k+1, INF);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    int last = i == 0 ? 0 : a[i-1];
    vector<ll> dp2(k+1, INF);
    if (last == a[i]) {
      for (int j = 0; j <= k; ++j) {
        dp2[j] = min(dp2[j], dp[j] + hot[a[i]]);
      }
      for (int j = 0; j <= k; ++j) {
        ll t = j == a[i] ? hot[a[i]] : cold[a[i]];
        dp2[a[i]] = min(dp2[a[i]], dp[j] + t);
      }
    } else {
      for (int j = 0; j <= k; ++j) {
        dp2[j] = min(dp2[j], dp[j] + cold[a[i]]);
      }
      for (int j = 0; j <= k; ++j) {
        ll t = j == a[i] ? hot[a[i]] : cold[a[i]];
        dp2[last] = min(dp2[last], dp[j] + t);
      }
    }

    dp = move(dp2);
  }

  ll ans = *min_element(dp.begin(), dp.end());
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
