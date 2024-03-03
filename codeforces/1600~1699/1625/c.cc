#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, l = 0, K = 0;
  cin >> n >> l >> K;

  vector<int> d(n+1);
  for (int i = 0; i < n; ++i) cin >> d[i];
  d[n] = l;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];


  constexpr i64 INF = numeric_limits<int>::max();
  vector<vector<i64>> memo(n+1, vector<i64>(K+1, -1));
  function<i64(int,int)> dp = [&](int i, int k) -> i64 {
    if (i == n) {
      return 0;
    }
    if (memo[i][k] >= 0) {
      return memo[i][k];
    }

    i64 ans = dp(i+1, k) + (d[i+1] - d[i]) * a[i];
    int remove = 0;
    for (int j = i+1; j < n; ++j) {
      remove++;
      if (remove > k) {
        break;
      }
      ans = min(ans, dp(j+1, k-remove) + (d[j+1] - d[i]) * a[i]);
    }
    return memo[i][k] = ans;
  };

  i64 ans = INF;
  for (int k = 0; k <= K; ++k) {
    ans = min(ans, dp(0, k));
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
