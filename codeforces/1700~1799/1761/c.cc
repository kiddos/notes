#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<int> degree(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (b[i][j] == '1') {
        adj[i].push_back(j);
        degree[j]++;
      }
    }
  }

  int id = 1;
  vector<vector<int>> ans(n);
  queue<int> q;
  for (int i = 0; i < n; ++i) if (degree[i] == 0) {
    q.push(i);
  }

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      ans[node].push_back(id);

      for (int parent : adj[node]) {
        if (--degree[parent] == 0) q.push(parent);
        ans[parent].push_back(id);
      }

      id++;
    }
  }

  for (vector<int>& A : ans) {
    cout << A.size() << " ";
    for (int num : A) cout << num << " ";
    cout << endl;
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
