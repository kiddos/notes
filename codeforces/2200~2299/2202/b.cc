#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(2, -1)));
  auto dp = [&](const auto& self, int i, int b1, int b2) -> bool {
    if (i >= n) {
      return true;
    }
    if (memo[i][b1][b2] >= 0) {
      return memo[i][b1][b2];
    }

    bool ans = false;
    if (s[i] == '?') {
      ans = self(self, i+1, 1-b1, b2) || self(self, i+1, b1, 1-b2);
    } else {
      int current = s[i] - 'a';
      if (current == b1) {
        ans = ans || self(self, i+1, 1-b1, b2);
      }
      if (current == b2) {
        ans = ans || self(self, i+1, b1, 1-b2);
      }
    }
    return memo[i][b1][b2] = ans;
  };

  bool ans = dp(dp, 0, 0, (n-1)%2);
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
