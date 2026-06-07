#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;

i64 memo[2001][2][2][2001];

void solve() {
  int m = 0, d = 0;
  cin >> m >> d;
  string a, b;
  cin >> a >> b;

  memset(memo, -1, sizeof(memo));

  int n = a.length();
  auto dp = [&](const auto& self, int i, bool is_low, bool is_high, int mod) -> i64 {
    if (i >= n) {
      return mod == 0 ? 1 : 0;
    }

    // cout << "dp(" << i << ',' << is_low << "," << is_high << "," << mod << ")" << endl;
    if (memo[i][is_low][is_high][mod] >= 0) {
      return memo[i][is_low][is_high][mod];
    }

    bool is_even = (i+1) % 2 == 0;
    i64 ans = 0;
    int high = is_high ? b[i] - '0' : 9;
    int low = is_low ? a[i] - '0' : 0;
    if (is_even) {
      if (d >= low && d <= high) {
        ans = self(self, i+1, is_low && d == low, is_high && d == high, (mod * 10 + d) % m);
      }
    } else {
      for (int d1 = low; d1 <= high; ++d1) {
        if (d1 == d) {
          continue;
        }
        i64 result = self(self, i+1, is_low && d1 == low, is_high && d1 == high, (mod * 10 + d1) % m);
        ans += result;
        ans %= MOD;
      }
    }
    return memo[i][is_low][is_high][mod] = ans;
  };

  i64 ans = dp(dp, 0, true, true, 0);
  cout << ans <<endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
