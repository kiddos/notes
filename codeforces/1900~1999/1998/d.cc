#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[i-1].push_back(i);
  }
  for (auto& [u, v] : edges) {
    adj[u].push_back(v);
  }

  vector<int> elsie(n+1, n+1);
  elsie[1] = 0;
  for (int node = 1; node <= n; ++node) {
    for (int next_node : adj[node]) {
      elsie[next_node] = min(elsie[next_node], elsie[node] + 1);
    }
  }

  vector<int> p(n+2);
  for (int i = 0; i < m; ++i) {
    auto [u, v] = edges[i];
    // node x > u
    // node x + t + 1 < v => x < v - t - 1
    int t = elsie[u];
    int start = u + 1;
    int end = v - t - 1;
    if (start <= end) {
      // cout << start << " ~ " << end << endl;
      p[start] ++;
      p[end] --;
    }
  }

  for (int i = 1; i <= n; ++i) {
    p[i] += p[i-1];
  }

  // for (int node = 1; node <= n; ++node) {
  //   cout << p[node] << " ";
  // }
  // cout << endl;

  string ans;
  for (int s = 1; s < n; ++s) {
    if (p[s]) {
      ans.push_back('0');
    } else {
      ans.push_back('1');
    }
  }

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
