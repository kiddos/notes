#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  auto get_factor = [&](int x) -> vector<int> {
    vector<int> f;
    for (int d = 1; d * d <= x; ++d) {
      if (x % d == 0) {
        f.push_back(d);
        f.push_back(x / d);
      }
    }
    sort(f.begin(), f.end());
    f.resize(unique(f.begin(), f.end()) - f.begin());
    return f;
  };

  vector<int> memo(n+1, -1);
  function<int(int)> dp = [&](int x) -> int {
    if (x == 1) {
      return 1;
    }
    if (memo[x] >= 0) {
      return memo[x];
    }
    vector<int> factors = get_factor(x);
    int ans = x;
    for (int f : factors) {
      if (f != x) {
        ans = max(ans, dp(f) + x);
      }
    }
    return memo[x] = ans;
  };

  int ans = dp(n);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
