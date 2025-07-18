#include <bits/stdc++.h>

using namespace std;

typedef float f_t;
typedef complex<f_t> C;

void fft(vector<C>& a) {
  int n = a.size(), L = 31 - __builtin_clz(n);
  static vector<C> R(2, 1);
  static vector<C> rt(2, 1);
  for (static int k = 2; k < n; k *= 2) {
    R.resize(n);
    rt.resize(n);
    auto x = polar((f_t)1.0, acos((f_t)-1.0) / k);
    for (int i = k; i < 2 * k; i++)
      rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
  }
  vector<int> rev(n);
  for (int i = 0; i < n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        C z = rt[j + k] * a[i + j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
      }
    }
  }
}

template <class T>
vector<vector<f_t>> conv2d(const vector<vector<T>>& a,
                           const vector<vector<T>>& b) {
  // Uses a 2D generalization of the "two in one trick"
  // (at http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf)
  // to reduce the number of FFTs from 3(N + M) to 2(N + M)
  if (a.empty() || b.empty() || a[0].empty() || b[0].empty()) return {};
  const int output_n = a.size() + b.size() - 1;
  const int output_m = a[0].size() + b[0].size() - 1;
  // (n, m) are (output_n, output_m) rounded up to the next power of 2
  const int n = 1 << (32 - __builtin_clz(output_n));
  const int m = 1 << (32 - __builtin_clz(output_m));
  const int max_in_rows = max(a.size(), b.size());
  const f_t nm4 = n * m * 4;
  vector<vector<C>> in(n, vector<C>(m));
  vector<vector<C>> out(n, vector<C>(m));
  vector<vector<f_t>> result(output_n, vector<f_t>(output_m));
  // pack both real inputs into a single complex matrix
  for (int i = 0; i < a.size(); i++) {
    copy(a[i].begin(), a[i].end(), in[i].begin());
  }
  for (int i = 0; i < b.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      in[i][j].imag(b[i][j]);
    }
  }
  // perform a 2D FFT by doing 1D FFTs on each row and column (order doesn't
  // matter)
  for (int i = 0; i < max_in_rows; i++) {
    fft(in[i]);
  }
  vector<C> col(n);
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      col[i] = in[i][j];
    }
    fft(col);
    for (int i = 0; i < n; i++) {
      in[i][j] = col[i] * col[i];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      out[i][j] = in[-i & (n - 1)][-j & (m - 1)] - conj(in[i][j]);
    }
  }

  // perform another 2D FFT
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      col[i] = out[i][j];
    }
    fft(col);
    for (int i = 0; i < n; i++) {
      out[i][j] = col[i];
    }
  }
  for (int i = 0; i < output_n; i++) {
    fft(out[i]);
    for (int j = 0; j < output_m; j++) {
      result[i][j] = out[i][j].imag() / nm4;
    }
  }
  return result;
}

int solve(vector<vector<int>>& matrix, vector<vector<int>>& target) {
  // Reverse the rows and columns of matrix so the output of the convolution is
  // the cross-correlation between target and matrix
  for (auto& row : matrix) {
    reverse(row.begin(), row.end());
  }
  reverse(matrix.begin(), matrix.end());
  vector<vector<f_t>> corr = conv2d(target, matrix);
  int result = 0;
  for (int i = 0; i < corr.size(); i++) {
    for (int j = 0; j < corr[i].size(); j++) {
      int val = round(corr[i][j]);
      result = max(result, val);
    }
  }
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // code here...
  return 0;
}

