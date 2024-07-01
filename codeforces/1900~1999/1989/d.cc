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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<i64> c(m);
  for (int i = 0; i < m; ++i) {
    cin >> c[i];
  }

  int max_a = *max_element(a.begin(), a.end());
  constexpr int INF = numeric_limits<int>::max();
  vector<i64> min_take(max_a+1, INF);
  for (int i = 0; i < n; ++i) {
    min_take[a[i]] = min(min_take[a[i]], (i64)a[i] - b[i]);
  }
  for (int i = 1; i <= max_a; ++i) {
    min_take[i] = min(min_take[i], min_take[i-1]);
  }
  vector<i64> dp(max_a+1);
  for (int i = 1; i <= max_a; ++i) {
    if (min_take[i] == INF) continue;

    dp[i] = 2;
    if (i - min_take[i] >= 0) {
      dp[i] += dp[i- min_take[i]];
    }
  }

  // for (int i = 0; i <= max_a; ++i) {
  //   cout << min_take[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i <= max_a; ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;

  i64 ans = 0;
  for (int i = 0; i < m; ++i) {
    if (c[i] <= max_a) {
      ans += dp[c[i]];
    } else {
      i64 extra = c[i] - max_a;
      i64 take = (extra + min_take[max_a] - 1) / min_take[max_a];
      ans += take * 2;
      c[i] -= take * min_take[max_a];
      // cout << "c[i]=" << c[i] << endl;
      if (c[i] >= 0) {
        ans += dp[c[i]];
      }
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
