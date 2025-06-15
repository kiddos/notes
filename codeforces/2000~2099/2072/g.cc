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

i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  i64 x1 = 0, y1 = 0;
  i64 d = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

i64 mod_div(i64 a, i64 b, i64 m) {
  i64 x = 0, y = 0;
  i64 g = extended_euclidean(b, m, x, y);
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

  ModInt(int x) : val_((x % MOD + MOD) % MOD) {}

  ModInt(i64 x) : val_((x % MOD + MOD) % MOD) {}

  ModInt& operator+=(const ModInt& rhs) {
    val_ = (val_ + rhs.val_) % MOD;
    return *this;
  }

  const ModInt& operator-=(const ModInt& rhs) {
    val_ = (val_ - rhs.val_ + MOD) % MOD;
    return *this;
  }

  const ModInt& operator*=(const ModInt& rhs) {
    val_ = (1LL * val_ * rhs.val_) % MOD;
    return *this;
  }

  const ModInt inv() const {
    i64 val = mod_div(1, val_, MOD);
    return ModInt(val);
  }

  const ModInt& operator/=(const ModInt& rhs) { return *this *= rhs.inv(); }

  explicit operator int() const { return val_; }

  friend const ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) += rhs;
  }

  friend const ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) -= rhs;
  }

  friend const ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) *= rhs;
  }

  friend const ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) /= rhs;
  }

  friend ostream& operator<<(ostream& os, const ModInt& x) {
    return os << x.val_;
  }

 private:
  unsigned int val_;
};

constexpr int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

i64 rev(int n, int p) {
  i64 ans = 0;
  while (n > 0) {
    int digit = n % p;
    ans = ans * p + digit;
    n /= p;
  }
  return ans;
}

void solve() {
  i64 n = 0;
  i64 k = 0;
  cin >> n >> k;

  i64 sq = sqrt(n);
  Mint ans = 0;

  // 2 <= p <= sqrt(n)
  for (int p = 2; p <= min(sq, k); ++p) {
    ans += rev(n, p);
  }

  // p > n
  if (k > n) {
    ans += ((k - n) % MOD) * n;
  }

  // sqrt(n) < p <= n
  // for (int p = sq + 1; p <= min(n, k); ++p) {
  //   ans += p * (n - (n / p) * p);
  //   ans += (n / p);
  // }

  // auto find_same = [&](int l, int x) -> int {
  //   int r = min(n, k);
  //   int ans = l;
  //   while (l <= r) {
  //     int mid = l + (r-l) / 2;
  //     if (n / mid == x) {
  //       l = mid + 1;
  //       ans = mid;
  //     } else {
  //       r = mid-1;
  //     }
  //   }
  //   return ans;
  // };

  auto square_sum = [&](i64 x) -> Mint {
    Mint ans = x;
    ans *= (x + 1);
    ans *= (2 * x + 1);
    ans /= 6;
    return ans;
  };

  int p = sq + 1;
  i64 bound = min(n, k);
  while (p <= bound) {
    int p2 = min(bound, n / (n / p));
    // - (n/p) * p * p
    int len = p2 - p + 1;
    Mint subtract = square_sum(p2) - square_sum(p - 1);
    subtract *= (n / p);
    ans -= subtract;

    // (n / p)
    Mint add1 = len * (n / p);
    ans += add1;

    Mint add2 = (p2 + p);
    add2 *= len;
    add2 /= 2;
    add2 *= n;
    ans += add2;

    p = p2+1;
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
