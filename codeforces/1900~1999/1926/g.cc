#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 2; i <= n; ++i) cin >> a[i];

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[i].push_back(a[i]);
    adj[a[i]].push_back(i);
  }

  string s;
  cin >> s;
  s = " " + s;

  auto get_type = [&](int node) -> int {
    char c = s[node];
    if (c == 'C') return 0;
    else if (c == 'P') return 1;
    else if (c == 'S') return 2;
    return -1;
  };

  vector<vector<int>> memo(n+1, vector<int>(3, -1));
  function<int(int,int,char)> dp = [&](int node, int p, int type) -> int {
    int current_type = get_type(node);
    if (current_type == 1 && (type == 2 || type == 0)) {
      return n;
    }
    if (current_type == 2 && (type == 1 || type == 0)) {
      return n;
    }

    if (memo[node][type] >= 0) {
      return memo[node][type];
    }

    int ans = 0;
    for (int next_node : adj[node]) if (next_node != p) {
      if (type == 0) {
        ans += min({
          dp(next_node, node, 0),
          dp(next_node, node, 1) + 1,
          dp(next_node, node, 2) + 1,
        });
      } else if (type == 1) {
        ans += min({
          dp(next_node, node, 0) + 1,
          dp(next_node, node, 1),
          dp(next_node, node, 2) + 1,
        });
      } else if (type == 2) {
        ans += min({
          dp(next_node, node, 0) + 1,
          dp(next_node, node, 1) + 1,
          dp(next_node, node, 2),
        });
      }
    }
    return memo[node][type] = ans;
  };


  int ans = min({
    dp(1, -1, 0),
    dp(1, -1, 1),
    dp(1, -1, 2),
  });

  std::cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}