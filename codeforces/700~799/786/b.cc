#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0, s = 0;
  cin >> n >> q >> s;
  int m = 1;
  while (m < n) {
    m *= 2;
  }

  int offset = m*4;
  int size = m*8;
  vector<vector<pair<int,i64>>> adj(size+1);

  vector<int> node_ids(m+1);
  auto map_id_to_node = [&](const auto& self, int id, int tl, int tr) -> void {
    if (tl > tr) {
      return;
    }
    if (tl == tr) {
      node_ids[tl] = id;
      adj[id + offset].push_back({id, 0});
      adj[id].push_back({id + offset, 0});
      return;
    }
    int tm = tl + (tr - tl) / 2;
    self(self, id * 2, tl, tm);
    self(self, id * 2 + 1,  tm + 1, tr);

    adj[id].push_back({id * 2, 0});
    adj[id].push_back({id * 2 + 1, 0});
    adj[id*2+offset].push_back({id+offset, 0});
    adj[id*2+1+offset].push_back({id+offset, 0});
  };

  map_id_to_node(map_id_to_node, 1, 1, m);

  // for (int i = 1; i <= n; ++i) {
  //   cout << nodes[i] << " ";
  // }
  // cout << endl;

  auto add_edge_to = [&](const auto& self, int id, int tl, int tr, int source_id, int l, int r, i64 w) -> void {
    if (tl > tr) {
      return;
    }
    if (tr < l || tl > r) {
      return;
    }
    if (tl >= l && tr <= r) {
      adj[source_id].push_back({id, w});
      return;
    }
    int tm = tl + (tr - tl) / 2;
    self(self, id * 2, tl, tm, source_id, l, r, w);
    self(self, id * 2 + 1, tm + 1, tr, source_id, l, r, w);
  };

  auto add_edge_from = [&](const auto& self, int id, int tl, int tr, int l, int r, int target_id, i64 w) -> void {
    if (tl > tr) {
      return;
    }
    if (tr < l || tl > r) {
      return;
    }
    if (tl >= l && tr <= r) {
      adj[id + offset].push_back({target_id, w});
      return;
    }
    int tm = tl + (tr - tl) / 2;
    self(self, id * 2, tl, tm, l, r, target_id, w);
    self(self, id * 2 + 1, tm + 1, tr, l, r, target_id, w);
  };

  for (int i = 0; i < q; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int v = 0, u = 0;
      i64 w = 0;
      cin >> v >> u >> w;
      int id1 = node_ids[v], id2 = node_ids[u];
      adj[id1].push_back({id2, w});
    } else if (t == 2) {
      int v = 0, l = 0, r = 0;
      i64 w = 0;
      cin >> v >> l >> r >> w;
      add_edge_to(add_edge_to, 1, 1, m, node_ids[v], l, r, w);
    } else if (t == 3) {
      int v = 0, l = 0, r = 0;
      i64 w = 0;
      cin >> v >> l >> r >> w;
      add_edge_from(add_edge_from, 1, 1, m, l, r, node_ids[v], w);
    }
  }

  priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
  pq.push({0, node_ids[s]});
  constexpr i64 inf = 1e18;
  vector<i64> dists(size+1, inf);
  dists[node_ids[s]] = 0;

  while (!pq.empty()) {
    auto [dist, node_id] = pq.top();
    // cout << "node=" << node_id << endl;
    pq.pop();
    for (auto [next_node, w] : adj[node_id]) {
      i64 dist2 = dist + w;
      if (dist2 < dists[next_node]) {
        dists[next_node] = dist2;
        pq.push({dist2, next_node});
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    int node_id = node_ids[i];
    i64 d = dists[node_id];
    if (d >= inf) {
      cout << "-1 ";
    } else{
      cout << d << " ";
    }
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
