#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  string s;
  cin >> s;
  s = " " + s;

  vector<bool> visited(n+1);
  function<void(int, vector<int>&)> dfs = [&](int i, vector<int>& group) {
    if (visited[i]) {
      return;
    }
    visited[i] = true;
    group.push_back(i);
    dfs(p[i], group);
  };

  vector<int> ans(n+1);
  for (int i = 1; i <= n; ++i) {
    vector<int> g;
    if (!visited[i]) {
      dfs(i, g);
    }
    int black = 0;
    for (int j : g) {
      if (s[j] == '0') {
        black++;
      }
    }
    for (int j : g) {
      ans[j] = black;
    }
  }

  for (int i = 1; i <= n; ++i) {
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
