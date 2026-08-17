#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  auto dp = [&](const auto& self, int i, int b1, int b2) -> i64 {
    if (i == n) {
      return 1;
    }
    int last = b1+b2;
    i64 ans = 0;
    if (last == 0) {
      // current bit must be 1
      if (s[i] == '?' || s[i] == '1') {
        ans += self(self, i+1, 1, b1);
      }
    } else if (last == 1) {
      if (b1 == 1) {
        // current bit must be 1
        if (s[i] == '?' || s[i] == '1') {
          ans += self(self, i+1, 1, b1);
        }
      } else if (b1 == 0) {
        // current bit must be 0
        if (s[i] == '?' || s[i] == '0') {
          ans += self(self, i+1, 0, b1);
        }
      }
    } else if (last == 2) {
      // current bit must be 0
      if (s[i] == '?' || s[i] == '0') {
        ans += self(self, i+1, 0, b1);
      }
    }
    ans %= MOD;
    return ans;
  };

  i64 ans = 0;
  for (int b2 = 0; b2 < 2; ++b2) {
    if (s[0] != '?' && (s[0]-'0') != b2) {
      continue;
    }
    for (int b1 = 0; b1 < 2; ++b1) {
      if (s[1] != '?' && (s[1]-'0') != b1) {
        continue;
      }

      ans += dp(dp, 2, b1, b2);
      ans %= MOD;
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
