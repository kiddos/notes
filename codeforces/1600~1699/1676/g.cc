#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    int p = 0;
    cin >> p;
    adj[p].push_back(i);
  }
  string s;
  cin >> s;
  s = " " + s;


  int ans = 0;
  function<pair<int,int>(int)> dfs = [&](int node) -> pair<int,int> {
    int black = 0, white = 0;
    for (int next_node : adj[node]) {
      auto [b, w] = dfs(next_node);
      black += b;
      white += w;
    }
    black += s[node] == 'B';
    white += s[node] == 'W';
    ans += black == white;
    return {black, white};
  };

  dfs(1);

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
