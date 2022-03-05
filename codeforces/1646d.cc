#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int u, v;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0;
  cin >> n;
  vector<Edge> edges;
  for (int i = 0; i < n-1; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.push_back(Edge{u-1, v-1});
  }

  if (n == 2) {
    cout << "2 2\n";
    cout << "1 1" << endl;
    return 0;
  }

  vector<vector<int>> adj(n);
  vector<int> indegree(n);
  for (int i = 0; i < n-1; ++i) {
    auto [u, v] = edges[i];
    adj[u].push_back(v);
    adj[v].push_back(u);
    indegree[u]++;
    indegree[v]++;
  }

  vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(2, {-1, -1}));
  function<pair<int,int>(int,int,int)> f = [&](int node, int good, int parent) {
    pair<int, int>& ans = dp[node][good];
    if (ans.first >= 0) return ans;
    ans.first = good;
    ans.second = good ? -((int)adj[node].size()) : -1;
    for (int neighbor : adj[node]) {
      if (neighbor == parent) continue;
      if (!good) {
        auto result = max(f(neighbor, 1-good, node), f(neighbor, good, node));
        ans.first += result.first;
        ans.second += result.second;
      } else {
        auto result = f(neighbor, 1-good, node);
        ans.first += result.first;
        ans.second += result.second;
      }
    }
    return ans;
  };
  pair<int, int> result = max(f(0, 1, -1), f(0, 0, -1));

  vector<bool> is_good(n);
  function<void(pair<int,int>,int,int)> build = [&](pair<int,int> value, int node, int parent) {
    if (value == dp[node][0]) {
      is_good[node] = false;
      for (int neighbor : adj[node]) {
        if (neighbor != parent) {
          auto next_value = max(dp[neighbor][0], dp[neighbor][1]);
          build(next_value, neighbor, node);
        }
      }
    } else {
      is_good[node] = true;
      for (int neighbor : adj[node]) {
        if (neighbor != parent) {
          build(dp[neighbor][0], neighbor, node);
        }
      }
    }
  };
  build(result, 0, -1);

  cout << result.first << " " << -result.second << '\n';
  for (int node = 0; node < n; ++node) {
    if (!is_good[node]) {
      cout << 1 << ' ';
    } else {
      cout << adj[node].size() << ' ';
    }
  }
  cout << endl;
  return 0;
}
