#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> w(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<int> degree(n+1);
  for (auto [u, v] : edges) {
    degree[u]++;
    degree[v]++;
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  for (int node = 1; node <= n; ++node) {
    if (degree[node] > 1) {
      pq.push({w[node], node});
    }
  }

  vector<i64> ans(n);
  for (auto [u, v] : edges) {
    ans[n-1] += w[u] + w[v];
  }

  for (int k = n-2; k >= 1; --k) {
    auto [w_node, node] = pq.top();
    pq.pop();
    ans[k] = ans[k+1] - w_node;
    if (--degree[node] > 1) {
      pq.push({w[node], node});
    }
  }

  for (int k = 1; k < n; ++k) {
    cout << ans[k] << " ";
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
