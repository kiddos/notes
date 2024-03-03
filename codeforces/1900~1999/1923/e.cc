#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) cin >> c[i];

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<map<int,i64>> dp(n+1);
  i64 ans = 0;
  function<void(int,int)> dfs = [&](int node, int p) {
    int current_color = c[node];

    int size = 0;
    int largest = -1;
    for (int next_node : adj[node]) if (next_node != p) {
      dfs(next_node, node);
      if ((int)dp[next_node].size() > size) {
        largest = next_node;
        size = dp[next_node].size();
      }
    }

    for (int next_node : adj[node]) if (next_node != p) {
      if (next_node == largest) {
        continue;
      }

      for (auto& [c, count] : dp[next_node]) {
        if (c != current_color) {
          ans += count * dp[largest][c];
        }
        dp[largest][c] += count;
      } 
    }

    if (largest != -1) {
      swap(dp[node], dp[largest]);
    }
    ans += dp[node][current_color];
    dp[node][current_color] = 1;
  };

  dfs(1, -1);

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
