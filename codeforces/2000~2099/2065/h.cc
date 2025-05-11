#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;
constexpr int MOD = 998244353;

vector<i64> p2(MAX_N+1, 1);
void precompute() {
  for (int i = 1; i <= MAX_N; ++i) {
    p2[i] = p2[i-1] * 2;
    p2[i] %= MOD;
  }
}

template <typename T, typename F, T DEFAULT>
class SegmentTreeImpl {
 public:
  SegmentTreeImpl(int n) : n(n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    data_ = vector<T>(max_size);
  }

  SegmentTreeImpl(vector<T>& data) {
    int n = data.size();
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    data_ = vector<T>(max_size);
    build_tree(data, 0, 0, n - 1);
  }

  void build_tree(vector<T>& data, int i, int tl, int tr) {
    if (tl == tr) {
      data_[i] = data[tl];
      return;
    }
    int tm = tl + (tr - tl) / 2;
    build_tree(data, i * 2 + 1, tl, tm);
    build_tree(data, i * 2 + 2, tm + 1, tr);
    data_[i] = merge(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

  T query(int i, int tl, int tr, int ql, int qr) {
    if (ql > qr) return DEFAULT;
    if (tr < ql || tl > qr) return DEFAULT;
    if (tl >= ql && tr <= qr) return data_[i];

    int tm = tl + (tr - tl) / 2;
    T left = query(i * 2 + 1, tl, tm, ql, min(tm, qr));
    T right = query(i * 2 + 2, tm + 1, tr, max(tm, ql), qr);
    return merge(left, right);
  }

  T query(int ql, int qr) { return query(0, 0, n - 1, ql, qr); }

  void update(int i, int tl, int tr, int index, const T& val) {
    if (tl == tr) {
      data_[i] += val;
      return;
    }

    int tm = tl + (tr - tl) / 2;
    if (index <= tm) {
      update(i * 2 + 1, tl, tm, index, val);
    } else {
      update(i * 2 + 2, tm + 1, tr, index, val);
    }
    data_[i] = merge(data_[i * 2 + 1], data_[i * 2 + 2]);
  }

  void update(int index, T val) { update(0, 0, n - 1, index, val); }

 private:
  int n;
  vector<T> data_;

  inline T merge(T x, T y) { return F{}(x, y); }
};

template <typename T>
struct SumFunctor {
  T operator()(T a, T b) const {
    return (a + b) % MOD;
  }
};

using SegmentTree = SegmentTreeImpl<i64, SumFunctor<i64>, 0>;

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

using Mint = ModInt<MOD>;  

void solve() {
  string s;
  cin >> s;
  int q = 0;
  cin >> q;
  vector<int> v(q);
  for (int i = 0; i < q; ++i) {
    cin >> v[i];
  }
  int n = s.length();

  Mint ans = p2[n]-1;
  SegmentTree p_zero(n), p_one(n), s_zero(n), s_one(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      p_one.update(i, p2[i]);
      s_one.update(i, p2[n-i-1]);
    } else {
      p_zero.update(i, p2[i]);
      s_zero.update(i, p2[n-i-1]);
    }
  }

  for (int j = 0; j < n; ++j) {
    // for (int i = 0; i < j; ++i) {
    //   if (s[j] != s[i]) {
    //     i64 p1 = power(2, i);
    //     i64 p2 = power(2, n-j-1);
    //     ans += (p1 * p2) % MOD;
    //   }
    // }
    if (s[j] == '1') {
      i64 zero_sum = p_zero.query(0, j-1);
      ans += zero_sum * p2[n-j-1];
    } else {
      i64 one_sum = p_one.query(0, j-1);
      ans += one_sum * p2[n-j-1];
    }
  }

  auto update = [&](int k) {
    // for (int i = 0; i < k; ++i) {
    //   if (s[k] != s[i]) {
    //     i64 p1 = power(2, i);
    //     i64 p2 = power(2, n-k-1);
    //     ans -= p1 * p2;
    //   }
    // }
    if (s[k] == '1') {
      i64 zero_sum = p_zero.query(0, k-1);
      ans -= zero_sum * p2[n-k-1];
    } else {
      i64 one_sum = p_one.query(0, k-1);
      ans -= one_sum * p2[n-k-1];
    }

    // for (int j = k+1; j < n; ++j) {
    //   if (s[k] != s[j]) {
    //     i64 p1 = power(2, k);
    //     i64 p2 = power(2, n-j-1);
    //     ans -= p1 * p2;
    //   }
    // }
    if (s[k] == '1') {
      i64 zero_sum = s_zero.query(k+1, n-1);
      ans -= zero_sum * p2[k];
    } else {
      i64 one_sum = s_one.query(k+1, n-1);
      ans -= one_sum * p2[k];
    }

    if (s[k] == '1') {
      p_one.update(k, -p2[k]);
      p_zero.update(k, p2[k]);
      s_one.update(k, -p2[n-k-1]);
      s_zero.update(k, p2[n-k-1]);
      s[k] = '0';
    } else {
      p_zero.update(k, -p2[k]);
      p_one.update(k, p2[k]);
      s_zero.update(k, -p2[n-k-1]);
      s_one.update(k, p2[n-k-1]);
      s[k] = '1';
    }

    // for (int i = 0; i < k; ++i) {
    //   if (s[k] != s[i]) {
    //     i64 p1 = power(2, i);
    //     i64 p2 = power(2, n-k-1);
    //     ans += p1 * p2;
    //   }
    // }
    if (s[k] == '1') {
      i64 zero_sum = p_zero.query(0, k-1);
      ans += zero_sum * p2[n-k-1];
    } else {
      i64 one_sum = p_one.query(0, k-1);
      ans += one_sum * p2[n-k-1];
    }

    // for (int j = k+1; j < n; ++j) {
    //   if (s[k] != s[j]) {
    //     i64 p1 = power(2, k);
    //     i64 p2 = power(2, n-j-1);
    //     ans += p1 * p2;
    //   }
    // }
    if (s[k] == '1') {
      i64 zero_sum = s_zero.query(k+1, n-1);
      ans += zero_sum * p2[k];
    } else {
      i64 one_sum = s_one.query(k+1, n-1);
      ans += one_sum * p2[k];
    }
  };

  // cout << "ans=" << ans << endl;
  for (int i = 0; i < q; ++i) {
    update(v[i]-1);
    cout << ans << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
