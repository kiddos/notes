#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
 
  string t = "narek";
  vector<vector<vector<int>>> states;
  constexpr int INF = 1e7;
  for (int i = 0; i < n; ++i) {
    vector<vector<int>> state(5, vector<int>(5, -INF));
    for (int start = 0; start < 5; ++start) {
      for (int j = 0, k = start, len = 0; j < m; ++j) {
        if (s[i][j] == t[k]) {
          len++;
          state[start][k] = len * 2;
          k = (k + 1) % 5;
        }
      }
    }
    states.push_back(state);
  }
 
  vector<int> dp(5, -INF);
 
  for (int i = 0; i < n; ++i) {
    vector<int> dp2 = dp;
    // cout << "states:" << endl;
    int remove = 0;
    for (char ch : s[i]) {
      if (t.find(ch) != string::npos) {
        remove++;
      }
    }
    for (int r = 0; r < 5; ++r) {
      dp2[r] = max(dp2[r], states[i][0][r] - remove);
    }
    for (int l = 0; l < 5; ++l) {
      for (int r = 0; r < 5; ++r) {
        dp2[r] = max(dp2[r], dp[(l-1 + 5) % 5] + states[i][l][r] - remove);
      }
      // cout << endl;
    }
    // cout << endl;
 
    dp = std::move(dp2);
    // for (int i = 0; i < 5; ++i) {
    //   cout << dp[i] << " ";
    // }
    // cout << endl;
  }
 
  int ans = max(dp[4], 0);
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
