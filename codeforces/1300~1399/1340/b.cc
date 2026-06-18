#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int turn_on_required(const string& s1, const string& s2) {
  int len = s1.length();
  int ans = 0;
  for (int i = 0; i < len; ++i) {
    if (s1[i] == s2[i]) {
      continue;
    }
    if (s1[i] == '1' && s2[i] == '0') {
      return -1;
    }
    if (s1[i] == '0' && s2[i] == '1') {
      ans++;
    }
  }
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<string> digits = {"1110111", "0010010", "1011101", "1011011",
                           "0111010", "1101011", "1101111", "1010010",
                           "1111111", "1111011"};

  vector<vector<int>> memo(n, vector<int>(k+1, -1));
  string ans(n, ' ');
  auto dp = [&](const auto& self, int i, int j) -> int {
    if (j < 0) {
      return false;
    }
    if (i == n) {
      return j == 0;
    }
    if (memo[i][j] >= 0) {
      return memo[i][j];
    }
    bool possible = false;
    for (int d = 9; d >= 0; --d) {
      int ops = turn_on_required(s[i], digits[d]);
      if (ops < 0) {
        continue;
      }
      int result = self(self, i+1, j-ops);
      if (result) {
        ans[i] = d + '0';
        possible = true;
        break;
      }
    }
    return memo[i][j] = possible;
  };

  bool possible = dp(dp, 0, k);
  if (!possible) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
