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

  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
    ModInt ans = lhs;
    ans += rhs;
    return ans;
  }

  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
    ModInt ans = lhs;
    ans -= rhs;
    return ans;
  }

  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
    ModInt ans = lhs;
    ans *= rhs;
    return ans;
  }

  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
    ModInt ans = lhs;
    ans /= rhs;
    return ans;
  }

  friend ostream& operator<<(ostream& os, const ModInt& x) {
    return os << x.val_;
  }

 private:
  unsigned int val_;
};

constexpr int MOD = 998244353;
using Mint = ModInt<MOD>;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> count2(n);
  for (int i = 0, two = 0; i < n; ++i) {
    if (a[i] == 2) {
      two++;
    } else if (a[i] == 3) {
      count2[i] = two;
    }
  }

  Mint suffix = 0, three = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 3) {
      suffix += power(2, count2[i], MOD);
      three += 1;
    }
  }

  Mint ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ans += suffix - three;
    } else if (a[i] == 2) {
      suffix /= 2;
    } else if (a[i] == 3) {
      suffix -= 1;
      three -= 1;
    }
  }
  cout << (int) ans << endl;
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
