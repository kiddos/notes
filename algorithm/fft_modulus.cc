#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

using cd = complex<long double>;

int reverse(int i, int bits) {
  int r = 0;
  for (int b = 0; b < bits; ++b) {
    if (i & (1 << b)) {
      r |= (1 << (bits - 1 - b));
    }
  }
  return r;
}

template<bool INVERT>
void fft(vector<cd>& a) {
  int n = a.size();
  int bits = 31 - __builtin_clz(n);

  for (int i = 0; i < n; ++i) {
    int r = reverse(i, bits);
    if (i < r) {
      swap(a[i], a[r]);
    }
  }

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * std::numbers::pi / len * (INVERT ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      int half = len / 2;
      for (int j = 0; j < half; ++j) {
        cd a1 = a[i+j], a2 = a[i+j+half] * w;
        a[i+j] = a1 + a2;
        a[i+j+half] = a1 - a2;
        w *= wlen;
      }
    }
  }

  if constexpr (INVERT) {
    for (cd& ai : a) {
      ai /= n;
    }
  }
}

template <int MOD>
vector<int> multiply(vector<int>& a, vector<int>& b) {
  int n = 1;
  int size = a.size() + b.size();
  while (n < size) {
    n <<= 1;
  }

  const int C = sqrt(MOD);
  vector<cd> A(n), B(n);
  for (int i = 0; i < (int)a.size(); ++i) {
    A[i] = cd((double) a[i] / C, a[i] % C);
  }
  for (int i = 0; i < (int)b.size(); ++i) {
    B[i] = cd((double) b[i] / C, b[i] % C);
  }

  fft<false>(A);
  fft<false>(B);

  vector<cd> out1(n), out2(n);
  for (int i = 0; i < n; ++i) {
    int j = -i & (n - 1);
		out1[j] = (A[i] + conj(A[j])) * B[i] / (2.0L * n);
		out2[j] = (A[i] - conj(A[j])) * B[i] / (2.0L * n) / cd(0, 1);
  }
  fft<false>(out1);
  fft<false>(out2);

  vector<int> result(n);
  for (int i = 0; i < n; ++i) {
    i64 x = round(out1[i].real());
    x = ((x % MOD) + MOD) % MOD;
    x *= C;
    x %= MOD;
    x *= C;
    x %= MOD;
    i64 y = round(out1[i].imag()) + round(out2[i].real());
    y = ((y % MOD) + MOD) % MOD;
    y *= C;
    y %= MOD;
    i64 z = round(out2[i].imag());
    z = ((z % MOD) + MOD) % MOD;
    result[i] = (x + y) % MOD;
    result[i] += z;
    result[i] %= MOD;
  }
  return result;
}

void solve() {
  vector<int> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> b1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  vector<int> result = {9, 26, 50, 80, 115, 154, 196, 240, 285, 240, 196, 154, 115, 80, 50, 26, 9};
  constexpr int MOD = 998244353;
  vector<int> c1 = multiply<MOD>(a1, b1);
  for (int i = 0; i < (int)result.size(); ++i) {
    assert(result[i] == c1[i]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
