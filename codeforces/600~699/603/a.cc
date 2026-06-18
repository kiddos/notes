#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> dp1(n, vector<int>(2));
  for (int i = 0; i < n; ++i) {
    int b = s[i]-'0';
    if (i > 0) {
      dp1[i][b] = max(dp1[i-1][b], dp1[i-1][1-b] + 1);
      dp1[i][1-b] = dp1[i-1][1-b];
    } else {
      dp1[i][b] = 1;
    }
  }

  vector<vector<int>> dp2(n, vector<int>(2));
  for (int i = 0; i < n; ++i) {
    int b = s[i]-'0';
    if (i > 0) {
      dp2[i][b] = max({dp1[i-1][b]+1, dp2[i][b], dp2[i-1][1-b] + 1});
      dp2[i][1-b] = max({dp2[i-1][1-b], dp1[i-1][1-b]});
    } else {
      dp2[i][b] = 1;
    }
  }

  vector<vector<int>> dp3(n, vector<int>(2));
  for (int i = 0; i < n; ++i) {
    int b = s[i]-'0';
    if (i > 0) {
      dp3[i][b] = max({dp2[i-1][b]+1, dp3[i][b], dp3[i-1][1-b] + 1});
      dp3[i][1-b] = max({dp3[i-1][1-b], dp2[i-1][1-b]});
    } else {
      dp3[i][b] = 1;
    }
  }

  int ans = max(dp3[n-1][0], dp3[n-1][1]);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
