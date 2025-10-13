#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int size = n * (n-1) / 2 - k;

  vector<vector<bool>> dp(n+1, vector<bool>(size+1));
  dp[0][0] = true;
  vector<vector<pair<int,int>>> p(n+1, vector<pair<int,int>>(size+1, {-1, -1}));

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= size; ++j) {
      if (dp[i][j]) {
        for (int l = 1; l <= n; ++l) {
          int len = l * (l-1) / 2;
          if (j+len <= size && i+l <= n) {
            dp[i+l][j+len] = true;
            p[i+l][j+len] = {i, j};
          }
        }
      }
    }
  }

  if (!dp[n][size]) {
    cout  << "0" << endl;
    return;
  }

  vector<int> block;
  pair<int,int> state = {n, size};
  while (true) {
    auto [n0, size0] = p[state.first][state.second];
    if (n0 < 0 || size0 < 0) {
      break;
    }

    int len = state.first - n0;
    block.push_back(len);
    state = {n0, size0};
  }

  // for (int b : block) {
  //   cout << b << " ";
  // }
  // cout << endl;

  vector<int> ans;
  int last = n;
  for (int b : block) {
    for (int i = last-b+1; i <= last; ++i) {
      ans.push_back(i);
    }
    last -= b;
  }
  while (last >= 1) {
    ans.push_back(last--);
  }
  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
