#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<int> state(n+1);
  function<bool(int)> find_cycle = [&](int x) -> bool {
    if (x < 1 || x > n) {
      return false;
    }
    if (state[x]) {
      return state[x] == 1;
    }
    state[x] = 1;
    if (find_cycle(x + a[x])) {
      return true;
    }
    state[x] = 2;
    return false;
  };

  for (int i = 1; i <= n; ++i) {
    if (state[i] == 0) {
      find_cycle(i);
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << state[i] << " ";
  // }
  // cout << endl;

  int lead_to_cycle = 0;
  for (int i = 1; i <= n; ++i) {
    if (state[i] == 1) {
      lead_to_cycle++;
    }
  }

  vector<vector<int>> adj(n+1);
  for (int i = 1; i <= n; ++i) {
    int j = i + a[i];
    if (j >= 1 && j <= n) {
      adj[j].push_back(i);
    }
  }

  vector<int> nodes(n+1);
  function<void(int)> count_nodes = [&](int node) {
    if (nodes[node]) {
      return;
    }

    nodes[node]++;
    for (int prev_node : adj[node]) {
      count_nodes(prev_node);
      nodes[node] += nodes[prev_node];
    }
  };

  // cout << "cycle=" << lead_to_cycle << endl;

  int current = 1;
  vector<bool> visited(n+1);
  i64 stuck = 0;
  while (current >= 1 && current <= n && !visited[current]) {
    visited[current] = true;

    if (state[current] == 1) {
      stuck += lead_to_cycle;
    } else {
      count_nodes(current);
      stuck += nodes[current];
      stuck += lead_to_cycle;
    }
    current = current + a[current];
  }

  // cout << "stuck=" << stuck << endl;
  i64 total = n * (2 * n +1);
  i64 ans = total - stuck;
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
