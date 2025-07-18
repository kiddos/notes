#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

using cd = complex<double>;

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

vector<int> multiply(vector<int>& a, vector<int>& b) {
  vector<cd> A(a.begin(), a.end());
  vector<cd> B(b.begin(), b.end());
  int n = 1;
  int size = a.size() + b.size();
  while (n < size) {
    n <<= 1;
  }
  A.resize(n);
  B.resize(n);

  fft<false>(A);
  fft<false>(B);
  for (int i = 0; i < n; ++i) {
    A[i] *= B[i];
  }
  fft<true>(A);

  vector<int> result(n);
  for (int i = 0; i < n; ++i) {
    result[i] = round(A[i].real());
  }
  int carry = 0;
  for (int i = 0; i < n; ++i) {
    result[i] += carry;
    carry = result[i] / 10;
    result[i] %= 10;
  }
  return result;
}

void solve() {
  vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> b = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  string result = "121932631112635269";
  vector<int> c = multiply(a, b);
  int size = c.size();
  for (int i = 0, k = result.length()-1; i < size; ++i, --k) {
    if (k >= 0) {
      int digit = result[k] - '0';
      assert(c[i] == digit);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
