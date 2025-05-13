#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({a[i], i});
  }

  vector<vector<int>> adj(n);
  auto add_edge = [&](int u, int v, bool reversed) {
    if (!reversed) {
      adj[u].push_back(v);
    } else {
      adj[v].push_back(u);
    }
  };

  for (int r = 1; p.size() > 1; ++r) {
    int size = p.size();
    queue<int> q;
    vector<bool> visited(n);
    for (int i = 0; i < size; ++i) {
      if (p[i].first == r) {
        if (i > 0 && p[i-1].first != r) {
          if (!visited[i]) {
            visited[i] = true;
            q.push(i);
          }
          add_edge(p[i].second, p[i-1].second, r % 2 == 0);
        }

        if (i+1 < size && p[i+1].first != r) {
          if (!visited[i]) {
            visited[i] = true;
            q.push(i);
          }
          add_edge(p[i].second, p[i+1].second, r % 2 == 0);
        }
      }
    }

    while (!q.empty()) {
      for (int s = q.size(); s > 0; --s) {
        int idx = q.front();
        q.pop();

        if (idx > 0 && p[idx-1].first == r && !visited[idx-1]) {
          visited[idx-1] = true;
          q.push(idx-1);
          add_edge(p[idx-1].second, p[idx].second, r % 2 == 0);
        }
        if (idx+1 < size && p[idx+1].first == r && !visited[idx+1]) {
          visited[idx+1] = true;
          q.push(idx+1);
          add_edge(p[idx+1].second, p[idx].second, r % 2 == 0);
        }
      }
    }

    vector<pair<int,int>> p2;
    for (auto [ai, i] : p) {
      if (ai != r) {
        p2.push_back({ai, i});
      }
    }
    p = std::move(p2);
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << i << " -> ";
  //   for (int j : adj[i]) cout << j << " ";
  //   cout << endl;
  // }

  vector<vector<int>> adj1(n);
  vector<int> degree(n);
  for (int u = 0; u < n; ++u) {
    for (int v : adj[u]) {
      adj1[v].push_back(u);
    }
    degree[u] = adj[u].size();
  }

  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (degree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> ans(n);
  int k = 1;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int idx = q.front();
      q.pop();
      ans[idx] = k++;

      for (int j : adj1[idx]) {
        degree[j]--;
        if (degree[j] == 0) {
          q.push(j);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
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
