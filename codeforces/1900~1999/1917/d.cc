#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n+1) {}

  int get(int i) {
    int total = 0;
    while (i > 0) {
      total += data_[i];
      i -= (i & -i);
    }
    return total;
  }

  void update(int i, int x) {
    int n = data_.size();
    while (i < n) {
      data_[i] += x;
      i += (i & -i);
    }
  }

 private:
  vector<int> data_;
};

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  vector<int> q(k);
  for (int i = 0; i < k; ++i) cin >> q[i];

  FenwickTree tree1(k+2);
  i64 inversion = 0;
  for (int i = 0; i < k; ++i) {
    inversion += tree1.get(k+1) - tree1.get(q[i]+1);
    inversion %= MOD;
    tree1.update(q[i]+1, 1);
  }

  i64 ans = (inversion * n) % MOD;

  int m = 2 * n + 1;
  FenwickTree tree2(m+1);
  for (int i = 0; i < n; ++i) {
    int y = p[i];
    i64 sum = (i64) k * (k+1) / 2;
    i64 s = k-1;
    while (y <= m) {
      i64 count = tree2.get(min(m, y*2)) - tree2.get(y);
      ans += count * sum;
      ans %= MOD;

      y *= 2;
      sum += max(s, 0LL);
      s--;
    }

    y = p[i];
    sum = (i64) k * (k-1) / 2;
    s = k-1;
    while (y > 0) {
      i64 count = tree2.get(y) - tree2.get(y / 2);
      ans += count * sum;
      ans %= MOD;

      y /= 2;
      sum -= max(s, 0LL);
      s--;
    }

    tree2.update(p[i], 1);
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
