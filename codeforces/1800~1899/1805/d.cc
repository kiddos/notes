#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (parent_[x] != x) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  bool join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return false;
    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
    } else {
      parent_[py] = px;
      rank_[px]++;
    }
    return true;
  }

 private:
  vector<int> parent_, rank_;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.push_back({u, v});
  }

  vector<vector<int>> adj(n+1);
  for (auto& [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto find_endpoint = [&](int start) -> int {
    queue<int> q;
    q.push(start);
    int end_point = start;
    vector<bool> visited(n+1);
    visited[start] = true;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int node = q.front();
        q.pop();
        for (int next_node : adj[node]) if (!visited[next_node]) {
          visited[next_node] = true;
          q.push(next_node);
          end_point = next_node;
        }
      }
    }
    return end_point;
  };

  int single_end = find_endpoint(1);

  int max_dist = 0;
  auto find_endpoints = [&](vector<int> start) -> vector<int> {
    queue<int> q;
    vector<bool> visited(n+1);
    for (int node : start) {
      q.push(node);
      visited[node] = true;
    }

    vector<int> endpoints;
    int step = 0;
    while (!q.empty()) {
      vector<int> e;
      for (int size = q.size(); size > 0; --size) {
        int node = q.front();
        q.pop();
        for (int next_node : adj[node]) if (!visited[next_node]) {
          visited[next_node] = true;
          q.push(next_node);
          e.push_back(next_node);
        }
      }
      if (e.size() > 0) {
        endpoints = move(e);
      }
      max_dist = max(max_dist, step++);
    }
    return endpoints;
  };

  auto compute_levels = [&](vector<int>& start) -> vector<vector<int>> {
    queue<int> q;
    vector<bool> visited(n+1);
    for (int node : start) {
      q.push(node);
      visited[node] = true;
    }

    vector<vector<int>> levels;
    while (!q.empty()) {
      vector<int> l;
      for (int size = q.size(); size > 0; --size) {
        int node = q.front();
        q.pop();
        for (int next_node : adj[node]) if (!visited[next_node]) {
          visited[next_node] = true;
          q.push(next_node);
          l.push_back(next_node);
        }
      }
      levels.push_back(l);
    }
    levels.pop_back();
    // reverse(levels.begin(), levels.end());
    return levels;
  };

  vector<int> a = find_endpoints({single_end});
  vector<int> b = find_endpoints(a);
  vector<vector<int>> a_levels = compute_levels(a);
  vector<vector<int>> b_levels = compute_levels(b);

  /*
  cout << "a: ";
  for (int s : a) cout << s << " ";
  cout << endl;
  cout << "b: ";
  for (int e : b) cout << e << " ";
  cout << endl;
  cout << "max dist: " << max_dist << endl;

  cout << "level a: " << endl;
  for (vector<int>& l : a_levels) {
    for (int node : l) cout << node << " ";
    cout << endl;
  }
  cout << "level b: " << endl;
  for (vector<int>& l : b_levels) {
    for (int node : l) cout << node << " ";
    cout << endl;
  }
  */

  queue<int> q;
  vector<bool> visited(n+1);
  for (int s : a) {
    q.push(s);
    visited[s] = true;
  }
  for (int e : b) {
    q.push(e);
    visited[e] = true;
  }

  DisjointSet ds(n+1);
  vector<int> ans;
  int components = n;
  for (int k = n; k >= 1; --k) {
    if (k <= max_dist) {
      for (int node : a_levels[k-1]) {
        if (ds.join(single_end, node)) {
          components--;
        }
      }
      for (int node : b_levels[k-1]) {
        if (ds.join(single_end, node)) {
          components--;
        }
      }
    }

    ans.push_back(components);
  }

  reverse(ans.begin(), ans.end());
  for (int c : ans) cout << c << " ";
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
