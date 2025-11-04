#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<int> in_degree(n+1);
  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    in_degree[b]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (in_degree[i] == 0) {
      q.push(i);
    }
  }

  constexpr int inf = 1e9;
  vector<int> dp(n+1, -inf);
  vector<int> prev(n+1);
  dp[1] = 0;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();

      for (int next_node : adj[node]) {
        if (dp[node] + 1 > dp[next_node]) {
          dp[next_node] = dp[node] + 1;
          prev[next_node] = node;
        }

        if (--in_degree[next_node] == 0) {
          q.push(next_node);
        }
      }
    }
  }

  if (dp[n] < 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  int current = n;
  vector<int> ans = {n};
  while (current != 1) {
    current = prev[current];
    ans.push_back(current);
  }
  reverse(ans.begin(), ans.end());

  cout << ans.size() << endl;
  for (int node : ans) {
    cout << node << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
