#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

pair<int,int> alice(int a, int b) {
  cout << a << " " << b << endl;
  int i = 0, c = 0;
  cin >> i >> c;
  return {i, c};
}

pair<int, int> bob_read() {
  int a = 0, b = 0;
  cin >> a >> b;
  return {a, b};
}

void bob_answer(int i, int c) {
  cout << i << " " << c << endl;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> adj(n+1);
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // check if this graph is a bipartite graph
  vector<int> colors(n+1);
  function<bool(int,int)> dfs = [&](int node, int c) -> bool {
    if (colors[node]) {
      return colors[node] == c;
    }
    colors[node] = c;

    for (int next_node : adj[node]) {
      if (!dfs(next_node, 3 - c)) {
        return false;
      }
    }
    return true;
  };

  bool is_bipartite = dfs(1, 1);
  if (is_bipartite) {
    cout << "Bob" << endl;
    // color=1, or color=2 must always be an option
    vector<int> group1, group2;
    for (int i = 1; i <= n; ++i) {
      if (colors[i] == 1) {
        group1.push_back(i);
      } else {
        group2.push_back(i);
      }
    }
    int i = 0, j = 0;
    while (i < (int)group1.size() && j < (int)group2.size()) {
      auto [a, b] = bob_read();
      if (a == 1 || b == 1) {
        int node = group1[i++];
        bob_answer(node, 1);
      } else {
        int node = group2[j++];
        bob_answer(node, 2);
      }
    }
    while (i < (int)group1.size()) {
      auto [a, b] = bob_read();
      int node = group1[i++];
      if (a != 2) {
        bob_answer(node, a);
      } else {
        bob_answer(node, b);
      }
    }
    while (j < (int)group2.size()) {
      auto [a, b] = bob_read();
      int node = group2[j++];
      if (a != 1) {
        bob_answer(node, a);
      } else {
        bob_answer(node, b);
      }
    }
  } else {
    // just keep giving the same color a b again and again
    // there will always be an edge that shares the same color vertex
    cout << "Alice" << endl;
    for (int i = 1; i <= n; ++i) {
      alice(1, 2);
    }
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
