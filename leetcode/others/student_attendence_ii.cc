#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution1 {
 public:
  int checkRecord(int n) {
    vector<int> present(n);
    vector<int> late(n);
    vector<int> absent(n);
    vector<int> present_without_absent(n);
    vector<int> late_without_absent(n);

    present[0] = late[0] = absent[0] = 1;
    present_without_absent[0] = late_without_absent[0] = 1;
    if (n > 1) {
      late[1] = 3;
      late_without_absent[1] = 2;
    }

    for (int i = 1; i < n; ++i) {
      present[i] = ((present[i-1] + late[i-1]) % MOD + absent[i-1]) % MOD;
      absent[i] = (present_without_absent[i-1] + late_without_absent[i-1]) % MOD;
      present_without_absent[i] = (present_without_absent[i-1] + late_without_absent[i-1]) % MOD;
      if (i >= 2) {
        late[i] = ((present[i-1] + absent[i-1]) % MOD + (present[i-2] + absent[i-2]) % MOD) % MOD;
        late_without_absent[i] = (present_without_absent[i-1] + present_without_absent[i-2]) % MOD;
      }
    }
    return ((present[n-1] + late[n-1]) % MOD + absent[n-1]) % MOD;
  }
};


class Matrix {
 public:
  Matrix(int n) : data(n, vector<int>(n)) {}

  Matrix operator*(const Matrix& m) {
    int n = data.size();
    Matrix output(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          output.data[i][j] += ((long)data[i][k] * (long)m.data[k][j]) % MOD;
          output.data[i][j] %= MOD;
        }
      }
    }
    return output;
  }

  vector<vector<int>> data;
};

class Solution2 {
 public:
  int checkRecord(int n) {
    Matrix ans(6);
    for (int i = 0; i < 6; ++i) ans.data[i][i] = 1;

    // 0 == total number with just P
    // 1 == total number with P and 1 late
    // 2 == total number with P and 2 late
    // 3 == total number with P and only 1 absent
    // 4 == total number with P and only 1 absent and 1 late
    // 5 == total number with P and only 1 absent and 2 late
    Matrix A(6);
    for (int i = 0; i < 6; ++i) A.data[i][2] = 1;
    A.data[1][0] = 1;
    A.data[2][1] = 1;
    A.data[3][5] = 1;
    A.data[4][3] = 1;
    A.data[4][5] = 1;
    A.data[5][4] = 1;
    A.data[5][5] = 1;

    n += 1;
    while (n > 0) {
      if (n % 2 == 1) {
        ans = ans * A;
      }
      A = A * A;
      n /= 2;
    }
    return ans.data[5][2];
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;

    int ans = Solution1().checkRecord(n);
    cout << ans << endl;

    ans = Solution2().checkRecord(n);
    cout << ans << endl;
  }
  return 0;
}
