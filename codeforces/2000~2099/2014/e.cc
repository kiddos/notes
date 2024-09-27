#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct State {
  i64 dist;
  int node;
  bool has_horse;
};

struct CompareState {
  bool operator()(const State& s1, const State& s2) const {
    if (s1.dist == s2.dist) {
      if (s1.node == s2.node) {
        return s2.has_horse < s1.has_horse;
      }
      return s1.node < s2.node;
    }
    return s1.dist < s2.dist;
  }
};

void solve() {
  int n = 0, m = 0, h = 0;
  cin >> n >> m >> h;
  vector<bool> has_horse(n+1);
  for (int i = 0; i < h; ++i) {
    int a = 0;
    cin >> a;
    has_horse[a] = true;
  }

  vector<vector<pair<int,i64>>> adj(n+1);
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0, w = 0;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  constexpr i64 INF = 1e12;
  auto min_dist = [&](int start) -> vector<vector<i64>> {
    set<State, CompareState> s;
    s.insert(State{0, start, has_horse[start]});
    vector<vector<i64>> dist(n+1, vector<i64>(2, INF));
    dist[start][has_horse[start]] = 0;
    while (!s.empty()) {
      auto [d, node, horse] = *s.begin();
      s.erase(s.begin());
      for (auto& [next_node, w] : adj[node]) {
        i64 d2 = d + (horse ? w / 2 : w);
        bool horse2 = horse || has_horse[next_node];
        if (d2 < dist[next_node][horse2]) {
          State s1 = State{dist[next_node][horse2], next_node, horse2};
          s.erase(s1);
          dist[next_node][horse2] = d2;
          State s2 = State{d2, next_node, horse2};
          s.insert(s2);
        }
      }
    }
    return dist;
  };

  vector<vector<i64>> d1 = min_dist(1);
  vector<vector<i64>> d2 = min_dist(n);
  i64 ans = INF;
  for (int node = 1; node <= n; ++node) {
    i64 e1 = min(d1[node][0], d1[node][1]);
    i64 e2 = min(d2[node][0], d2[node][1]);
    i64 meet_time = max(e1, e2);
    ans = min(ans, meet_time);
  }

  if (ans >= INF) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
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
