#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 power(i64 x, i64 n, i64 mod) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }

    n >>= 1;
    x = x * x;
    x %= mod;
  }
  return ans;
}

template <int MOD>
class ModInt {
 public:
  ModInt() : val_(0) {}

  ModInt(i64 x) : val_(x % MOD) {}

  ModInt(const ModInt& m) { val_ = m.val_; }

  ModInt(ModInt&& m) { val_ = m.val_; }

  constexpr ModInt& operator=(const ModInt& rhs) {
    val_ = rhs.val_;
    return *this;
  }

  constexpr ModInt& operator=(ModInt&& rhs) {
    val_ = rhs.val_;
    return *this;
  }

  constexpr ModInt& operator+=(const ModInt& rhs) {
    val_ = (val_ + rhs.val_) % MOD;
    return *this;
  }

  constexpr ModInt& operator-=(const ModInt& rhs) {
    val_ = (val_ - rhs.val_ + MOD) % MOD;
    return *this;
  }

  constexpr ModInt& operator*=(const ModInt& rhs) {
    val_ = (1LL * val_ * rhs.val_) % MOD;
    return *this;
  }

  constexpr ModInt inv() const {
    i64 val = power(val_, MOD - 2, MOD);
    return ModInt(val);
  }

  constexpr ModInt& operator/=(const ModInt& rhs) { return *this *= rhs.inv(); }

  explicit constexpr operator int() const { return val_; }

  friend constexpr ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
    ModInt ans = lhs;
    ans += rhs;
    return ans;
  }

  friend constexpr ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
    ModInt ans = lhs;
    ans -= rhs;
    return ans;
  }

  friend constexpr ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
    ModInt ans = lhs;
    ans *= rhs;
    return ans;
  }

  friend constexpr ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
    ModInt ans = lhs;
    ans /= rhs;
    return ans;
  }

  friend constexpr ostream& operator<<(ostream& os, const ModInt& x) {
    return os << x.val_;
  }

 private:
  unsigned int val_;
};

constexpr int MOD = 1000000007;
using Mint = ModInt<MOD>;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  if (k % 2 == 1) {
    cout << "1" << endl;
    return;
  }

  vector<i64> f(n+1, 1);
  vector<i64> inv_f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
  inv_f[n] = power(f[n], MOD-2, MOD);
  for (int i = n-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }

  auto C = [&](int N, int K) -> i64 {
    if (N < 0) return 0;
    if (K > N) return 0;

    i64 ans = f[N];
    ans *= inv_f[K];
    ans %= MOD;
    ans *= inv_f[N-K];
    ans %= MOD;
    return ans;
  };

  vector<vector<int>> adj(n+1);
  for (auto& [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> sizes(n+1);
  function<void(int,int)> compute_size = [&](int node, int p) {
    sizes[node] = 1;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      compute_size(next_node, node);
      sizes[node] += sizes[next_node];
    }
  };

  compute_size(1, 0);

  Mint ans = 0;
  for (int node = 1; node <= n; ++node) {
    i64 p1 = C(sizes[node], k / 2);
    i64 p2 = C(n - sizes[node], k / 2);
    i64 p = (p1 * p2) % MOD;
    ans += p;
  }
  ans /= C(n, k);
  ans += 1;

  cout << (int)ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
