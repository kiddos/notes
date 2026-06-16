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

  vector<vector<int>> adj(n+1);
  vector<int> degree(n+1);
  for (auto [a, b] : edges) {
    degree[a]++;
    degree[b]++;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  set<pair<int,int>> s(edges.begin(), edges.end());
  int ans = numeric_limits<int>::max();
  for (int i = 0; i < m; ++i) {
    auto [a, b] = edges[i];
    for (int c : adj[a]) {
      if (c == b) {
        continue;
      }
      if (s.count({b, c}) || s.count({c, b})) {
        int total = degree[a] + degree[b] + degree[c];
        // cout << "a=" << a << ",b=" << b << ",c=" << c << endl;
        ans = min(ans, total - 6);
      }
    }
    for (int c : adj[b]) {
      if (c == a) {
        continue;
      }
      if (s.count({a, c}) || s.count({c, c})) {
        int total = degree[a] + degree[b] + degree[c];
        // cout << "a=" << a << ",b=" << b << ",c=" << c << endl;
        ans = min(ans, total - 6);
      }
    }
  }

  if (ans == numeric_limits<int>::max()) {
    cout << "-1" << endl;
    return;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
