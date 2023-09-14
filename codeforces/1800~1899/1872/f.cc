#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) cin >> c[i];

  vector<int> fears(n+1);
  for (int i = 1; i <= n; ++i) {
    fears[a[i]]++;
  }

  queue<int> q;
  vector<bool> visited(n+1);
  for (int i = 1; i <= n; ++i) if (fears[i] == 0) {
    q.push(i);
    visited[i] = true;
  }

  vector<int> ans;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      ans.push_back(node);

      int parent = a[node];
      if (--fears[parent] == 0) {
        q.push(parent);
        visited[parent] = true;
      }
    }
  }

  for (int i = 1; i <= n; ++i) if (!visited[i]) {
    int min_cost = numeric_limits<int>::max();
    int x = i;
    vector<int> cycle;
    while (!visited[x]) {
      visited[x] = true;
      cycle.push_back(x);
      min_cost = min(min_cost, c[x]);

      x = a[x];
    }

    int m = cycle.size();
    for (int i = 0; i < m; ++i) if (c[cycle[i]] == min_cost) {
      for (int j = i+1; j < m; ++j) {
        ans.push_back(cycle[j]);
      }
      for (int j = 0; j <= i; ++j) {
        ans.push_back(cycle[j]);
      }
      break;
    }
  }

  for (int node : ans) cout << node << " ";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
