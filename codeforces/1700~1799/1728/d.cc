#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  constexpr int MIN_VAL = numeric_limits<int>::min();
  vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(26, MIN_VAL)));
  function<int(int,int,int)> dp = [&](int l, int r, int c) -> int {
    if (l > r) return 0;

    if (memo[l][r][c] > MIN_VAL) {
      return memo[l][r][c];
    }

    int c1 = s[l]-'a';
    int c2 = s[r]-'a';
    int len = r-l+1;
    int ans = 0;
    if (len % 2 == 0) {
      // alice
      int res1 = dp(l+1, r, c1);
      int res2 = dp(l, r-1, c2);
      ans = max(res1, res2);
    } else {
      // bob
      int d1 = dp(l+1, r, 0);
      int d2 = dp(l, r-1, 0);
      int res1 = d1 == 0 ? (c1 < c ? -1 : c1 > c ? 1 : 0) : d1;
      int res2 = d2 == 0 ? (c2 < c ? -1 : c2 > c ? 1 : 0) : d2;
      ans = min(res1, res2);
    }

    // cout << "[" << l << "][" << r << "][" << c << "]=" << ans << endl; 
    return memo[l][r][c] = ans;
  };

  int ans = dp(0, n-1, 0);
  if (ans > 0) {
    cout << "Alice" << endl;
  } else if (ans < 0) {
    cout << "Bob" << endl;
  } else {
    cout << "Draw" << endl;
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
