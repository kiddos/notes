#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> g(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (g[i][j] == '1') {
        adj[i].push_back(j);
      } else {
        adj[j].push_back(i);
      }
    }
  }

  vector<int> ans;
  vector<bool> visited(n);
  function<void(int)> top_sort = [&](int node) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj[node]) {
      top_sort(next_node);
    }
    ans.push_back(node+1);
  };

  for (int i = 0; i < n; ++i) {
    top_sort(i);
  }
  reverse(ans.begin(), ans.end());
  for (int x : ans) {
    cout << x << " ";
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
