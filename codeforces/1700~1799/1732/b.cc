#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(2,-1)));
  function<int(int,int,int)> dp = [&](int i, int force_one, int flip) {
    if (i >= n) return 0;
    if (memo[i][force_one][flip] >= 0) return memo[i][force_one][flip];

    int ans = 0;
    int d = (s[i]-'0' + flip) % 2;
    if (force_one) {
      if (d == 0) {
        ans = dp(i+1, force_one, (flip+1) % 2) + 1;
      } else {
        ans = dp(i+1, force_one, flip);
      }
    } else {
      if (d == 1) {
        ans = dp(i+1, 1, flip);
      } else {
        ans = min(dp(i+1, 1, (flip+1) % 2) + 1, dp(i+1, 0, flip));
      }
    }
    return memo[i][force_one][flip] = ans;
  };

  int ans = dp(0, 0, 0);
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
