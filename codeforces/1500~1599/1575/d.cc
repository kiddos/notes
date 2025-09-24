#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  vector<vector<vector<int>>> memo(n, vector<vector<int>>(10, vector<int>(25, -1)));
  auto dp = [&](const auto& self, int i, int x, int m) -> i64 {
    if (i == n) {
      if (m == 0) {
        return 1;
      } else {
        return 0;
      }
    }

    if (memo[i][x][m] >= 0) {
      return memo[i][x][m];
    }

    i64 ans = 0;
    if (s[i] == '_') {
      int start = i == 0 && n > 1 ? 1 : 0;
      for (int d = start; d <= 9; ++d) {
        int m2 = (m * 10 + d) % 25;
        ans += self(self, i+1, x, m2);
      }
    } else if (s[i] == 'X') {
      if (i != 0 || x != 0 || n == 1) {
        int m2 = (m * 10 + x) % 25;
        ans = self(self, i+1, x, m2);
      }
    } else {
      if (i != 0 || s[i] != '0' || n == 1) {
        int m2 = (m * 10 + s[i] - '0') % 25;
        ans = self(self, i+1, x, m2);
      }
    }
    return memo[i][x][m] = ans;
  };

  i64 ans = 0;
  auto p = s.find('X');
  if (p != string::npos) {
    for (int x = 0; x <= 9; ++x) {
      ans += dp(dp, 0, x, 0);
    }
  } else {
    ans += dp(dp, 0, 0, 0);
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
