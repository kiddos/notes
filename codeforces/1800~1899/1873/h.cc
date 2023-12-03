#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;
  vector<pair<int,int>> edges;
  for (int i = 0; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  if (a == b) {
    cout << "NO" << endl;
    return;
  }

  vector<vector<int>> adj(n+1);
  for (auto& [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> time(n+1);
  function<bool(int,int)> dfs = [&](int building, int t) -> bool {
    time[building] = t;

    // cout << "visiting: " << building << " time = " << t << endl;
    for (int next_building : adj[building]) {
      // cout << " next = " << next_building << endl;
      if (time[next_building] == 1 && t - time[next_building] >= 2) {
        return true;
      }

      if (!time[next_building]) {
        if (dfs(next_building, t+1)) {
          return true;
        }
      }
    }
    return false;
  };

  if (dfs(b, 1)) {
    // cout << "start in cycle" << endl;
    cout << "YES" << endl;
    return;
  }

  if (dfs(a, 1)) {
    cout << "NO" << endl;
    return;
  }

  auto compute_dist = [&](int start, int target) -> int {
    vector<bool> visited(n+1);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    vector<int> dist(n+1);
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int building = q.front();
        q.pop();

        for (int next_building : adj[building]) {
          if (visited[next_building]) continue;
          visited[next_building] = true;
          dist[next_building] = dist[building] + 1;
          q.push(next_building);
        }
      }
    }
    return dist[target];
  };


  fill(time.begin(), time.end(), 0);

  int entry = -1;
  function<void(int,int)> dfs2 = [&](int building, int t) {
    time[building] = t;
    for (int next_building : adj[building]) {
      if (time[next_building] && t - time[next_building] >= 2) {
        entry = next_building;
      }

      if (time[next_building]) continue;
      dfs2(next_building, t+1);
    }
  };


  dfs2(b, 1);

  // for (int i = 1; i <= n; ++i) {
  //   cout << marked[i] << " ";
  // }
  // cout << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << dist[i] << " ";
  // }
  // cout << endl;
  
  assert(entry > 0);

  // cout << "entry = " << entry << endl;
  int d1 = compute_dist(b, entry);
  int d2 = compute_dist(a, entry);
  // cout << "d1= " << d1 << " d2=" << d2 << endl;
  if (d1 < d2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
