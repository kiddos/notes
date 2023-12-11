#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> g(3);
  for (int i = 0; i < 3; ++i) cin >> g[i];

  string ans;
  vector<vector<bool>> visited(3, vector<bool>(3));
  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
  function<void(int,int,string&)> dfs = [&](int i, int j, string& s) {
    if (i < 0 || i >= 3 || j < 0 || j >= 3) return;
    if (visited[i][j]) return;

    visited[i][j] = true;
    s.push_back(g[i][j]);

    if (s.length() == 3) {
      if (ans.empty()) {
        ans = s;
      } else {
        ans = min(ans, s);
      }
    } else {
      for (vector<int>& d : delta) {
        dfs(i+d[0], j+d[1], s);
      }
    }
    s.pop_back();
    visited[i][j] = false;
  };

  string current;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      dfs(i, j, current);
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
