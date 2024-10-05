#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> r(n + 1);
  for (int i = 1; i <= n; ++i) cin >> r[i];

  vector<vector<int>> controls(n + 1);
  for (int i = 1; i <= m; ++i) {
    int x = 0;
    cin >> x;
    for (int j = 0; j < x; ++j) {
      int s = 0;
      cin >> s;
      controls[s].push_back(i);
    }
  }

  // 2-sat
  // since each room is controlled by exactly 2 switch
  //   x ^ y  = (-x | -y) & (x | y)
  // -(x ^ y) = (-x | y)  & (x | -y)

  vector<vector<int>> adj(m*2+1);
  for (int room = 1; room <= n; ++room) {
    int s1 = controls[room][0];
    int s2 = controls[room][1];
    if (r[room]) {
      // x -> y
      adj[s1].push_back(s2);
      // -y -> -x
      adj[s2 + m].push_back(s1 + m);

      // -x -> -y
      adj[s1 + m].push_back(s2 + m);
      // y -> x
      adj[s2].push_back(s1);
    } else {
      // x -> -y
      adj[s1].push_back(s2 + m);
      // y -> -x
      adj[s2].push_back(s1 + m);

      // -x -> y
      adj[s1 + m].push_back(s2);
      // -y -> x
      adj[s2 + m].push_back(s1);
    }
  }

  vector<int> ordering;
  vector<bool> visited(m*2+1);
  function<void(int)> dfs1 = [&](int node) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj[node]) {
      dfs1(next_node);
    }
    ordering.push_back(node);
  };

  for (int node = 1; node <= m * 2; ++node) {
    if (!visited[node]) {
      dfs1(node);
    }
  }

  vector<vector<int>> rev_adj(m*2 + 1);
  for (int node = 1; node <= 2 * m; ++node) {
    for (int next_node : adj[node]) {
      rev_adj[next_node].push_back(node);
    }
  }

  vector<int> components(m*2 + 1, -1);
  function<void(int,int)> dfs2 = [&](int node, int c) {
    if (components[node] >= 0) {
      return;
    }
    components[node] = c;
    for (int next_node : rev_adj[node]) {
      dfs2(next_node, c);
    }
  };

  reverse(ordering.begin(), ordering.end());
  int c = 1;
  for (int node : ordering) {
    dfs2(node, c++);
  }

  for (int node = 1; node <= m; ++node) {
    int not_node = node + m;
    if (components[node] == components[not_node]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
