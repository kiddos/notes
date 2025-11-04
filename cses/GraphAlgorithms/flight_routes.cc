#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<array<int,3>> edges;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  vector<vector<pair<int,int>>> adj(n+1);
  for (auto [a, b, c] : edges) {
    adj[a].push_back({b, c});
  }

  // constexpr i64 inf = 1e18;
  vector<priority_queue<i64>> dists(n+1);
  dists[1].push(0);

  multiset<pair<i64,int>> s;
  s.insert({0, 1});

  while (!s.empty()) {
    auto [d0, node] = *s.begin();
    s.erase(s.begin());

    for (auto [next_node, w] : adj[node]) {
      i64 d = d0 + w;
      if ((int)dists[next_node].size() >= k && d >= dists[next_node].top()) {
        continue;
      }

      dists[next_node].push(d);
      if ((int)dists[next_node].size() > k) {
        i64 largest_d = dists[next_node].top();
        dists[next_node].pop();
        s.erase(s.find({largest_d, next_node}));
      }
      s.insert({d, next_node});
    }
  }

  vector<i64> ans;
  while (!dists[n].empty()) {
    ans.push_back(dists[n].top());
    dists[n].pop();
  }
  reverse(ans.begin(), ans.end());
  for (i64 d : ans) {
    cout << d << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
