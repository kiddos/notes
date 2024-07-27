#include <bits/stdc++.h>

using namespace std;

int MaxSumSubMatrix(vector<vector<int>>& matrix) {
  int m = matrix.size();
  int n = matrix[0].size();

  int ans = numeric_limits<int>::min();
  for (int l = 0; l < n; ++l) {
    vector<int> row_sum(m);
    for (int r = l; r < n; ++r) {
      for (int i = 0; i < m; ++i) {
        row_sum[i] += matrix[i][r];
      }

      int current = 0;
      for (int i = 0; i < m; ++i) {
        current = max(current + row_sum[i], row_sum[i]);
        ans = max(ans, current);
      }
    }
  }
  return ans;
}

int MaxSumSubMatrix(vector<vector<int>>& matrix, int k) {
  int m = matrix.size();
  int n = matrix[0].size();

  int ans = numeric_limits<int>::min();
  for (int l = 0; l < n; ++l) {
    vector<int> row_sum(m);
    for (int r = l; r < n; ++r) {
      for (int i = 0; i < m; ++i) {
        row_sum[i] += matrix[i][r];
      }

      set<int> s = {0};
      int current = 0;
      for (int i = 0; i < m; ++i) {
        current += row_sum[i];
        auto p = s.lower_bound(current - k);
        if (p != s.end()) ans = max(ans, current - *p);
        s.insert(current);
      }
    }
  }
  return ans;
}

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int m = 0, n = 0;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> matrix[i][j];
      }
    }

    int k = 0;
    cin >> k;
    int ans = MaxSumSubMatrix(matrix, k);
    cout << "with limit k = " << k << " : " << ans << endl;

    cout << "without limit k: ";
    ans = MaxSumSubMatrix(matrix);
    cout << ans << endl;
  }
  return 0;
}
