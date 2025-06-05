#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, l = 0;
  cin >> n >> m >> l;

  vector<int> a(l);
  for (int i = 0; i < l; ++i) {
    cin >> a[i];
  }

  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.push_back({u, v});
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  pq.push({0, 1});
  constexpr int inf = numeric_limits<int>::max();
  vector<array<int,2>> dists(n+1, {inf, inf});
  dists[1][0] = 0;

  while (!pq.empty()) {
    auto [d0, node] = pq.top();
    pq.pop();

    for (int next_node : adj[node]) {
      int d1 = d0+1;
      if (d1 < dists[next_node][d1%2]) {
        dists[next_node][d1%2] = d1;
        pq.push({d1, next_node});
      }
    }
  }

  int smallest_odd = inf;
  for (int ai : a) {
    if (ai % 2 == 1) {
      smallest_odd = min(ai, smallest_odd);
    }
  }

  // for (int p = 0; p < 2; ++p) {
  //   for (int i = 1; i <= n; ++i) {
  //     cout << dists[i][p] << " ";
  //   }
  //   cout << endl;
  // }

  int sum = accumulate(a.begin(), a.end(), 0);
  int sum_parity = sum % 2;
  vector<bool> ans(n+1);
  for (int node = 1; node <= n; ++node) {
    if (dists[node][sum_parity] <= sum) {
      ans[node] = true;
    }
    if (smallest_odd < inf) {
      if (dists[node][1-sum_parity] <= sum - smallest_odd) {
        ans[node] = true;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i];
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
