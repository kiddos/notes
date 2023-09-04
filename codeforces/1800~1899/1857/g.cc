#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n), size_(n, 1) {
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
      size_[px] += size_[py];
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
      size_[py] += size_[px];
    } else {
      parent_[py] = px;
      rank_[px]++;
      size_[px] += size_[py];
    }
  }

  int size(int i) {
    int p = find(i);
    return size_[p];
  }

 private:
  vector<int> parent_, rank_, size_;
};

i64 power(i64 x, i64 n, i64 mod) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }

    x = x * x;
    x %= mod;
    n >>= 1;
  }
  return ans;
}

void solve() {
  constexpr int MOD = 998244353;
  int n = 0;
  cin >> n;
  i64 S = 0;
  cin >> S;

  vector<array<i64, 3>> edges;
  for (int i = 1; i < n; ++i) {
    i64 u = 0, v = 0, w = 0;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  sort(edges.begin(), edges.end(), [&](auto& e1, auto& e2) {
    return e1[2] < e2[2];
  });

  i64 ans = 1;
  DisjointSet ds(n+1);
  for (auto& [u, v, w] : edges) {
    i64 s1 = ds.size(u);
    i64 s2 = ds.size(v);

    ans *= power(S - w + 1, s1 * s2-1, MOD);
    ans %= MOD;
    ds.join(u, v);
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
