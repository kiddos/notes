#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
  int n = s.length();
  vector<int> dp(n);
  vector<int> last(26, -1);
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    if (last[c] >= 0) {
      int choice1 = (i-1 >= 0 ? dp[i-1] : 0) + 1;
      int choice2 = (last[c] -1 >= 0 ? dp[last[c]-1] : 0) + i - last[c] - 1;
      if (choice1 <= choice2) {
        dp[i] = choice1;
        last[c] = i;
      } else {
        dp[i] = choice2;
      }
    } else {
      dp[i] = (i-1 >= 0 ? dp[i-1] : 0) + 1;
      last[c] = i;
    }
  }
  // cout << "dp: ";
  // for (int d : dp) cout << d << " ";
  // cout << endl;
  return dp[n-1];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    string s;
    cin >> s;
    int ans = solve(s);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
