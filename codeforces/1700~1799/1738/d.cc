#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  int k = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i] > i) {
      k = i;
    }
  }

  vector<vector<int>> adj(n+2);
  for (int i = 1; i <= n; ++i) {
    adj[b[i]].push_back(i);
  };

  vector<bool> visited(n+2);
  vector<int> order;
  queue<int> q;
  q.push(0);
  q.push(n+1);

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      for (int next_node : adj[node]) {
        if (visited[next_node]) {
          continue;
        }
        visited[next_node] = true;
        q.push(next_node);
      }

      vector<int> temp;
      for (int next_node : adj[node]) {
        temp.push_back(next_node);
      }
      sort(temp.begin(), temp.end(), [&](int node1, int node2) {
        return adj[node1].size() < adj[node2].size();
      });
      order.insert(order.end(), temp.begin(), temp.end());
    }
  }

  vector<int> ans;
  for (int x : order) {
    if (x >= 1 && x <= n) {
      ans.push_back(x);
    }
  }

  cout << k << endl;
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
