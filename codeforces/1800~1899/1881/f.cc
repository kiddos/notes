#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<bool> marked(n+1);
  for (int i = 0; i < k; ++i) {
    int a = 0;
    cin >> a;
    marked[a] = true;
  }

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  constexpr int INF = 1000000000;
  function<void(int,int,vector<int>&)> compute_dist = [&](int node, int parent, vector<int>& dist) {
    for (int next_node : adj[node]) if (next_node != parent) {
      dist[next_node] = dist[node]+1;
      compute_dist(next_node, node, dist);
    }
  };
  
  auto find_marked = [&](vector<int>& dist) {
    int ans = 0;
    int d = -1;
    for (int node = 1; node <= n; ++node) if (marked[node]) {
      if (dist[node] > d) {
        d = dist[node];
        ans = node;
      }
    }
    return ans;
  };

  vector<int> dist1(n+1);
  compute_dist(1, -1, dist1);

  int node2 = find_marked(dist1);
  vector<int> dist2(n+1);
  compute_dist(node2, -1, dist2);

  // cout << "node2= " << node2 << endl;
  // for (int i = 1; i <= n; ++i) cout << dist2[i] << " ";
  // cout << endl;

  int node3 = find_marked(dist2);
  vector<int> dist3(n+1);
  compute_dist(node3, -1, dist3);

  // cout << "node3= " << node3 << endl;
  // for (int i = 1; i <= n; ++i) cout << dist3[i] << " ";
  // cout << endl;

  int ans = INF;
  for (int node = 1; node <= n; ++node) {
    int d = max(dist2[node], dist3[node]);
    ans = min(ans, d);
  }
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
