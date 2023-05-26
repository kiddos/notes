#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  ll x = 0, y = 0;
  cin >> n >> x >> y;

  string a, b;
  cin >> a >> b;

  vector<int> index;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      index.push_back(i);
    }
  }

  int m = index.size();

  if (m % 2 == 1) {
    cout << "-1" << endl;
    return;
  }

  if (m == 0) {
    cout << "0" << endl;
    return;
  }

  if (x >= y) {
    if (m == 2) {
      if (index[0]+1 == index[1]) {
        ll ans = min(x, 2 * y);
        cout << ans << endl;
      } else {
        ll ans = y;
        cout << ans << endl;
      }
    } else {
      ll ans = m / 2 * y;
      cout << ans << endl;
    }
  } else {
    auto cost = [&](int i1, int i2) {
      ll ans = x * (index[i2] - index[i1]);
      if (index[i2] != index[i1]+1) {
        ans = min(ans, y);
      }
      return ans;
    };

    constexpr ll INF = 1e18;
    vector<vector<ll>> dp(m, vector<ll>(m, INF));
    for (int i = 0; i < m-1; ++i) {
      dp[i][i+1] = min(dp[i][i+1], cost(i, i+1));
    }

    for (int len = 4; len <= m; len += 2) {
      for (int l = 0; l+len-1 < m; ++l) {
        int r = l + len - 1;
        dp[l][r] = min(dp[l][r], dp[l+1][r-1] + cost(l, r));
        dp[l][r] = min(dp[l][r], dp[l+2][r] + cost(l, l+1));
        dp[l][r] = min(dp[l][r], dp[l][r-2] + cost(r-1, r));
      }
    }

    ll ans = dp[0][m-1];
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
