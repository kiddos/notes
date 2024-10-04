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
  constexpr ModInt() : val_(0) {}

  constexpr ModInt(i64 x) : val_(x % MOD) {}

  constexpr ModInt(const ModInt<MOD>& m) { val_ = m.val_; }

  constexpr ModInt(ModInt<MOD>&& m) { val_ = m.val_; }

  constexpr ModInt<MOD>& operator=(const ModInt& rhs) {
    val_ = rhs.val_;
    return *this;
  }

  constexpr ModInt<MOD>& operator=(ModInt&& rhs) {
    val_ = rhs.val_;
    return *this;
  }

  constexpr ModInt<MOD>& operator+=(const ModInt& rhs) {
    val_ = (val_ + rhs.val_) % MOD;
    return *this;
  }

  constexpr ModInt<MOD>& operator-=(const ModInt& rhs) {
    val_ = (val_ - rhs.val_ + MOD) % MOD;
    return *this;
  }

  constexpr ModInt<MOD>& operator*=(const ModInt& rhs) {
    val_ = (1LL * val_ * rhs.val_) % MOD;
    return *this;
  }

  constexpr ModInt<MOD> inv() const {
    i64 val = power(val_, MOD - 2, MOD);
    return ModInt<MOD>(val);
  }

  constexpr ModInt<MOD>& operator/=(const ModInt<MOD>& rhs) { return *this *= rhs.inv(); }

  explicit operator int() const { return val_; }

  friend constexpr ModInt<MOD> operator+(const ModInt<MOD>& lhs, const ModInt<MOD>& rhs) {
    ModInt<MOD> ans = lhs;
    ans += rhs;
    return ans;
  }

  friend constexpr ModInt<MOD> operator-(const ModInt<MOD>& lhs, const ModInt<MOD>& rhs) {
    ModInt<MOD> ans = lhs;
    ans -= rhs;
    return ans;
  }

  friend constexpr ModInt<MOD> operator*(const ModInt<MOD>& lhs, const ModInt<MOD>& rhs) {
    ModInt<MOD> ans = lhs;
    ans *= rhs;
    return ans;
  }

  friend constexpr ModInt<MOD> operator/(const ModInt<MOD>& lhs, const ModInt<MOD>& rhs) {
    ModInt<MOD> ans = lhs;
    ans /= rhs;
    return ans;
  }

  friend ostream& operator<<(ostream& os, const ModInt<MOD>& x) {
    return os << x.val_;
  }

 private:
  i64 val_;
};

constexpr int MOD = 1000000007;
constexpr int MAX_BIT = 10;
using MInt = ModInt<MOD>;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  // double dp[MAX_BIT][MAX_BIT][2][2];
  MInt dp[MAX_BIT][MAX_BIT][2][2];
  for (int b1 = 0; b1 < MAX_BIT; ++b1) {
    for (int b2 = 0; b2 < MAX_BIT; ++b2) {
      // dp[b1][b2][0][0] = 1.0;
      // dp[b1][b2][1][0] = 0.0;
      // dp[b1][b2][0][1] = 0.0;
      // dp[b1][b2][1][1] = 0.0;
      dp[b1][b2][0][0] = 1;
      dp[b1][b2][1][0] = 0;
      dp[b1][b2][0][1] = 0;
      dp[b1][b2][1][1] = 0;
    }
  }

  MInt dp2[MAX_BIT][MAX_BIT][2][2];
  for (int i = 0; i < n; ++i) {
    // double dp2[MAX_BIT][MAX_BIT][2][2];
    // double select_p = p[i] / 10000.0;
    // double not_select_p = 1.0 - select_p;
    MInt select_p = MInt(p[i]) / 10000;
    MInt not_select_p = MInt(1) - select_p;
    for (int b1 = 0; b1 < MAX_BIT; ++b1) {
      int bit1 = a[i] & (1<<b1) ? 1 : 0;
      for (int b2 = 0; b2 < MAX_BIT; ++b2) {
        int bit2 = a[i] & (1<<b2) ? 1 : 0;
        for (int f1 = 0; f1 <= 1; ++f1) {
          for (int f2 = 0; f2 <= 1; ++f2) {
            dp2[b1][b2][f1][f2] =
              dp[b1][b2][f1][f2] * not_select_p +
              dp[b1][b2][bit1 ^ f1][bit2 ^ f2] * select_p;
          }
        }
      }
    }
    for (int b1 = 0; b1 < MAX_BIT; ++b1) {
      for (int b2 = 0; b2 < MAX_BIT; ++b2) {
        for (int f1 = 0; f1 <= 1; ++f1) {
          for (int f2 = 0; f2 <= 1; ++f2) {
            dp[b1][b2][f1][f2] = dp2[b1][b2][f1][f2];
          }
        }
      }
    }
  }

  // double expected = 0;
  MInt expected = 0;
  for (int i = 0; i < MAX_BIT; ++i) {
    for (int j = 0; j < MAX_BIT; ++j) {
      int power = 1 << (i + j);
      // double p = dp[i][j][1][1];
      MInt p = dp[i][j][1][1];
      expected += p * power;
    }
  }
  // cout << "expected: " << expected << endl;
  cout << expected << endl;
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
