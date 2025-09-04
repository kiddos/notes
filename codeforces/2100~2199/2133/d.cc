#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  vector<i64> memo(n, -1);
  auto dp = [&](const auto& self, int i) -> i64 {
    if (i <= 0) {
      return 0;
    }
    if (memo[i] >= 0) {
      return memo[i];
    }

    i64 ans = self(self, i-1) + 1;
    i64 fall = min((i64)i, h[i]);
    ans = max(ans, self(self, i-2) + fall);
    return memo[i] = ans;
  };

  i64 fall_damage = dp(dp, n-1);
  // cout << "fall damage=" << fall_damage << endl;

  i64 total_hit = accumulate(h.begin(), h.end(), 0LL);
  i64 ans = total_hit - fall_damage;
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
