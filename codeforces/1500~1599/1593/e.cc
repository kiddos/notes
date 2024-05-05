#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);

  int n = 0, k = 0;
  cin >> n >> k;
  vector<vector<int>> adj(n+1);
  vector<int> degree(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; ++i) if (degree[i] <= 1) {
    q.push(i);
  }

  int left = n;
  int ops = k;
  while (!q.empty() && ops > 0) {
    int s = q.size();
    for (int size = s; size > 0; --size) {
      int node = q.front();
      q.pop();
      for (int next_node : adj[node]) {
        if (--degree[next_node] == 1) {
          q.push(next_node);
        }
      }
    }
    left -= s;
    ops--;
  }

  cout << left << endl;
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
