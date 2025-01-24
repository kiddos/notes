#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 extended_euclid(i64 a, i64 b, i64& x, i64& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  i64 x1 = 0, y1 = 0;
  i64 g = extended_euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}

i64 mod_div(i64 a, i64 b, i64 m) {
  i64 x = 0, y = 0;
  i64 g = extended_euclid(b, m, x, y);
  if (g != 1) {
    return -1;
  } else {
    i64 inv_b = (x % m + m) % m;
    return (a * inv_b) % m;
  }
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
    i64 val = mod_div(1, val_, MOD);
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

constexpr int MOD = 998244353;
using Mint = ModInt<MOD>;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  vector<int> c = a, d = b;
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());

  Mint ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans *= min(c[i], d[i]);
  }

  cout << ans << " ";

  for (int i = 0; i < q; ++i) {
    int o = 0, x = 0;
    cin >> o >> x;
    if (o == 1) {
      // update a
      int index = upper_bound(c.begin(), c.end(), a[x]) - c.begin()-1;
      ans /= min(c[index], d[index]);
      a[x]++;
      c[index]++;
      ans *= min(c[index], d[index]);
    } else if (o == 2) {
      // update b
      int index = upper_bound(d.begin(), d.end(), b[x]) - d.begin()-1;
      ans /= min(c[index], d[index]);
      b[x]++;
      d[index]++;
      ans *= min(c[index], d[index]);
    }
    cout << ans << " ";
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
