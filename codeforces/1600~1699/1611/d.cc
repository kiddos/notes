#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) cin >> b[i];
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) cin >> p[i];

  int root = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i] == i) {
      root = i;
      break;
    }
  }

  vector<int> w(n+1);
  vector<int> temp(n+1);
  for (int i = 2; i <= n; ++i) {
    temp[p[i]] = temp[p[i-1]] + 1;
    w[p[i]] = temp[p[i]] - temp[b[p[i]]];
  }

  vector<int> dist(n+1);
  vector<vector<pair<int,int>>> adj(n+1);
  for (int i = 1; i <= n; ++i) {
    if (b[i] != i) {
      adj[b[i]].push_back({i, w[i]});
    }
  }

  function<void(int)> dfs = [&](int node) {
    for (auto [child, weight] : adj[node]) {
      dist[child] = dist[node] + weight;
      dfs(child);
    }
  };

  dfs(root);

  //for (int i = 1; i <= n; ++i) {
    //cout << dist[p[i]] << " ";
  //}
  //cout << endl;

  for (int i = 2; i <= n; ++i) {
    if (dist[p[i-1]] >= dist[p[i]]) {
      cout << "-1" << endl;
      return;
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << w[i] << " ";
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
