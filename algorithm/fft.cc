#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

using cd = complex<double>;

template<bool INVERT>
void fft(vector<cd>& a) {
  int n = a.size();
  if (n == 1) {
    return;
  }

  int m = n/2;
  vector<cd> a0(m), a1(m);
  for (int i = 0, k = 0; i < n; i += 2, ++k) {
    a0[k] = a[i];
    a1[k] = a[i+1];
  }
  fft<INVERT>(a0);
  fft<INVERT>(a1);

  double ang = 2 * std::numbers::pi / n * (INVERT ? -1 : 1);
  cd w(1), wn(cos(ang), sin(ang));
  for (int i = 0; 2 * i < n; ++i) {
    a[i] = a0[i] + w * a1[i];
    a[i + m] = a0[i] - w * a1[i];
    if constexpr (INVERT) {
      a[i] /= 2;
      a[i + m] /= 2;
    }
    w *= wn;
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
  // vector<int> a = {1, 2};
  // vector<int> b = {3, 4};
  // vector<int> c = multiply(a, b);
  // for (int coef : c) {
  //   cout << coef << " ";
  // }
  // cout<< endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
