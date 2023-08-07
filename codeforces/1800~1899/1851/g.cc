#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

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

  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
    } else {
      parent_[py] = px;
      rank_[px]++;
    }
  }

 private:
  vector<int> parent_, rank_;
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  
  vector<i64> h(n+1);
  for (int i = 1; i <= n; ++i) cin >> h[i];

  vector<array<i64, 3>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.push_back({max(h[u], h[v]), u, v});
  }

  sort(edges.begin(), edges.end());

  int q = 0;
  cin >> q;
  vector<array<i64, 5>> queries;
  for (int i = 0; i < q; ++i) {
    int a = 0, b = 0, e = 0;
    cin >> a >> b >> e;
    queries.push_back({h[a]+e, a, b, e, i});
  }

  sort(queries.begin(), queries.end());

  DisjointSet ds(n+1);
  vector<bool> ans(q);
  for (int i = 0, j = 0; i < q; ++i) {
    auto [x, a, b, e, idx] = queries[i];
    // cout << "a+e=" << x << ", query: " << idx <<endl;
    while (j < m && edges[j][0] <= x) {
      auto [y, u, v] = edges[j];
      // cout << "join " << u << ", " << v << endl;
      ds.join(u, v);
      j++;
    }

    int pa = ds.find(a);
    int pb = ds.find(b);
    ans[idx] = pa == pb;
  }

  for (int i = 0; i < q; ++i) {
    cout << (ans[i] ? "YES" : "NO") << endl;
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
