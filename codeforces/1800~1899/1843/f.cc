#include <bits/stdc++.h>

using namespace std;

struct Result {
  int sum, max_prefix, max_suffix, min_prefix, min_suffix, max_seg, min_seg;
  Result()
      : sum(0), max_prefix(0), max_suffix(0), min_prefix(0), min_suffix(0),
        max_seg(0), min_seg(0) {}
  Result(int x)
      : sum(x), max_prefix(max(x, 0)), max_suffix(max(x, 0)), min_prefix(min(x, 0)), min_suffix(min(x, 0)),
        max_seg(max(x, 0)), min_seg(min(x, 0)) {}

  Result(int sum, int max_prefix, int max_suffix, int min_prefix,
         int min_suffix, int max_seg, int min_seg)
      : sum(sum), max_prefix(max_prefix), max_suffix(max_suffix),
        min_prefix(min_prefix), min_suffix(min_suffix), max_seg(max_seg),
        min_seg(min_seg) {}
};

Result operator+(const Result& r1, const Result& r2) {
  return Result(r1.sum + r2.sum, max(r1.max_prefix, r1.sum + r2.max_prefix),
                max(r2.max_suffix, r1.max_suffix + r2.sum),
                min(r1.min_prefix, r1.sum + r2.min_prefix),
                min(r2.min_suffix, r1.min_suffix + r2.sum),
                max({r1.max_seg, r2.max_seg, r1.max_suffix + r2.max_prefix}),
                min({r1.min_seg, r2.min_seg, r1.min_suffix + r2.min_prefix}));
}

Result reverse(const Result& r) {
  return Result(
    r.sum, r.max_suffix, r.max_prefix, r.min_suffix, r.min_prefix, r.max_seg, r.min_seg
  );
}

ostream& operator<<(ostream& os, const Result& r) {
  os << "sum=" << r.sum << ", max_seg=" << r.max_seg << ", min_seg=" << r.min_seg
  << ", max_prefix=" << r.max_prefix << ", max_suffix=" << r.max_suffix
  << ", min_prefix=" << r.min_prefix << ", min_suffix=" << r.min_suffix;
  return os;
}

void solve() {
  constexpr int LOG = 20;

  int n = 0;
  cin >> n;

  int m = n + 3;
  vector<vector<int>> parent(m, vector<int>(LOG));
  vector<vector<Result>> results(m, vector<Result>(LOG));
  vector<int> depth(m);
  vector<int> xs(m, 1);
  int current_node = 1;

  for (int h = 0; h < LOG; ++h) {
    results[1][0] = Result(1);
    parent[1][h] = 1;
  }

  auto get_lca = [&](int u, int v) -> Result {
    Result r1, r2;

    if (depth[u] > depth[v]) {
      swap(u, v);
    }

    int depth_diff = depth[v] - depth[u];
    for (int h = 0; h < LOG; ++h) {
      if (depth_diff & (1 << h)) {
        r2 = results[v][h] + r2;
        v = parent[v][h];
      }
    }

    if (u == v) {
      Result total = reverse(r1) + Result(xs[u]) + r2;
      // cout << "r1=" << reverse(r1) << endl << 
        // "r2=" << r2 << endl;
      // cout << "debug1=" << reverse(r1) + r2 << endl;
      // cout << "debug2=" << reverse(r1) + Result(xs[u]) + r2 << endl;
      // cout << "result: " << total << endl;
      return total;
    } else {
      for (int h = LOG - 1; h >= 0; --h) {
        if (parent[u][h] != parent[v][h]) {
          r1 = results[u][h] + r1;
          r2 = results[v][h] + r2;

          u = parent[u][h];
          v = parent[v][h];
        }
      }

      r1 = results[u][0] + r1;
      r2 = results[v][0] + r2;

      int lca = parent[u][0];
      // cout << "r1=" << r1 << endl << "r2=" << r2 << endl;
      Result total = reverse(r1) + Result(xs[lca]) + r2;
      // cout << "result: " << total << endl;
      return total;
    }
  };

  for (int i = 0; i < n; ++i) {
    char op = '\0';
    cin >> op;
    if (op == '+') {
      int v = 0, x = 0;
      cin >> v >> x;

      int new_node = ++current_node;
      depth[new_node] = depth[v] + 1;
      parent[new_node][0] = v;
      xs[new_node] = x;

      results[new_node][0] = Result(x);
      // cout << "result=" << results[new_node][0] << endl;
      for (int h = 1; h < LOG; ++h) {
        parent[new_node][h] = parent[parent[new_node][h - 1]][h - 1];
        results[new_node][h] = results[parent[new_node][h - 1]][h - 1] + results[new_node][h-1];
        // cout << "merged: " << results[new_node][h] << endl;
        // cout << "parent=" << parent[new_node][h] <<  ", result=" << results[new_node][h] << endl;
      }
    } else if (op == '?') {
      int u = 0, v = 0, x = 0;
      cin >> u >> v >> x;
      Result r = get_lca(u, v);

      // cout << "query=" << r << ", x=" << x << endl;
      if (x >= r.min_seg && x <= r.max_seg) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
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
