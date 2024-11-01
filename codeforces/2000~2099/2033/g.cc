#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int q = 0;
  cin >> q;
  vector<pair<int,int>> queries;
  for (int i = 0; i < q; ++i) {
    int v = 0, k = 0;
    cin >> v >> k;
    queries.emplace_back(v, k);
  }

  vector<int> depths(n+1);
  function<void(int,int)> get_depths = [&](int node, int p) {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      depths[next_node] = depths[node] + 1;
      get_depths(next_node, node);
    }
  };
  get_depths(1, 1);

  vector<pair<int, int>> max_moves(n + 1);
  function<void(int, int)> get_max_moves = [&](int node, int p) {
    vector<int> ds;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      get_max_moves(next_node, node);
      int d = max_moves[next_node].first + 1;
      ds.push_back(d);
    }
    sort(ds.begin(), ds.end());
    max_moves[node].first = ds.empty() ? 0 : ds.back();
    if (!ds.empty()) {
      ds.pop_back();
    }
    max_moves[node].second = ds.empty() ? 0 : ds.back();
  };
  get_max_moves(1, 1);

  int L = ceil(log2(n));
  vector<vector<pair<int,int>>> binary_lift(n+1, vector<pair<int,int>>(L+1));
  function<void(int,int)> prepare_binary_lift = [&](int node, int p) {
    binary_lift[node][0].second = p;
    if (max_moves[node].first + 1 < max_moves[p].first) {
      binary_lift[node][0].first = max_moves[p].first - depths[p];
    } else {
      binary_lift[node][0].first = max_moves[p].second - depths[p];
    }

    for (int l = 1; l <= L; ++l) {
      int last_p = binary_lift[node][l-1].second;
      binary_lift[node][l].second = binary_lift[last_p][l-1].second;
      binary_lift[node][l].first = max(binary_lift[node][l-1].first, binary_lift[last_p][l-1].first);
    }

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      prepare_binary_lift(next_node, node);
    }
  };
  prepare_binary_lift(1, 1);

  // for (int l = 0; l <= L; ++l) {
  //   for (int node = 1; node <= n; ++node) {
  //     cout << binary_lift[node][l].first << " ";
  //   }
  //   cout << endl;
  // }

  auto answer_query = [&](int node, int k) -> int {
    int ans = max_moves[node].first - depths[node];
    int current = node;
    // cout << "query:" << node<< "," << k << endl;
    for (int l = L; l >= 0; --l) {
      if (k & (1<<l)) {
        ans = max(ans, binary_lift[current][l].first);
        current = binary_lift[current][l].second;
      }
    }
    // cout << "ans=" << ans << ",depth:" << depths[node] << endl;
    return ans + depths[node];
  };

  vector<int> ans;
  for (auto& [v, k] : queries) {
    ans.push_back(answer_query(v, k));
  }

  for (int i = 0; i < q; ++i) {
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
