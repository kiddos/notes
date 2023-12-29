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

constexpr int MOD = 998244353;

using MInt = ModInt<MOD>;

void solve() {
  i64 n = 0;
  cin >> n;

  map<i64, array<MInt, 3>> memo;
  function<array<MInt, 3>(i64)> compute = [&](i64 n) -> array<MInt, 3> {
    if (n == 1) {
      return {1, 0, 1};
    }
    if (memo.count(n)) {
      return memo[n];
    }

    array<MInt, 3> ans = {0, 0, 0};
    auto left = compute((n + 1) / 2);
    auto right = compute(n / 2);
    ans[0] = left[0] * 2 + right[0] * 2 + left[2] * right[2];
    ans[1] = left[1] + right[1] + right[0];
    ans[2] = left[2] * right[2] + left[2] + right[2];
    return memo[n] = ans;
  };

  auto result = compute(n);

  auto ans = result[0] + result[1];
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
