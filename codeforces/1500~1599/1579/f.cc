#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, d = 0;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  constexpr int INF = 100000000;
  vector<int> state(n);
  vector<int> memo(n);
  function<int(int)> dp = [&](int i) -> int {
    if (a[i] == 0) {
      return 0;
    }
    if (state[i]) {
      if (state[i] == 2) {
        return memo[i];
      } else {
        return INF;
      }
    }
    state[i] = 1;
    int ans = dp((i + d) % n) + 1;
    state[i] = 2;
    return memo[i] = ans;
  };

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int result = dp(i);
    if (result >= INF) {
      cout << "-1" << endl;
      return;
    }
    ans = max(ans, result);
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
