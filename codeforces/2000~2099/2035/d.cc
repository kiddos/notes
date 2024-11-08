#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// ax + by = g
i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  i64 x1 = 0, y1 = 0;
  i64 result = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return result;
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
    i64 x = 0, y = 0;
    extended_euclidean(val_, MOD, x, y);
    return ModInt(x);
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


i64 p2(i64 n) {
  i64 ans = 1;
  i64 x = 2;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }
    n >>= 1;
    x = x * x;
    x %= MOD;
  }
  return ans;
}

pair<int,int> count_p2(i64 x) {
  int twos = 0;
  while (x > 0 && x % 2 == 0) {
    twos ++;
    x >>= 1;
  }
  return {x, twos};
}

bool le(i64 x, i64 base, i64 p2) {
  if (base >= x) {
    return true;
  }
  while (p2) {
    base *= 2;
    p2--;
    if (base >= x) return true;
  }
  return false;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<pair<int,int>> s;
  vector<i64> ans(n);
  Mint prefix = 0;
  for (int i = 0; i < n; ++i) {
    auto [without_two, twos] = count_p2(a[i]);
    while (!s.empty() && le(s.back().first, without_two, twos)) {
      Mint val = p2(s.back().second);
      val *= s.back().first;
      prefix -= val;
      prefix += s.back().first;
      twos += s.back().second;
      s.pop_back();
    }
    s.push_back({without_two, twos});
    Mint x = without_two;
    x *= p2(twos);
    prefix += x;
    ans[i] = (int) prefix;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
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
