#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<vector<vector<int>>> rows(10, vector<vector<int>>(n));
  vector<vector<vector<int>>> cols(10, vector<vector<int>>(n));
  vector<int> min_rows(10, n), min_cols(10, n);
  vector<int> max_rows(10), max_cols(10);
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      int d = s[r][c] - '0';
      rows[d][c].push_back(r);
      cols[d][r].push_back(c);

      min_rows[d] = min(min_rows[d], r);
      max_rows[d] = max(max_rows[d], r);
      min_cols[d] = min(min_cols[d], c);
      max_cols[d] = max(max_cols[d], c);
    }
  }

  vector<int> ans(10);
  for (int d = 0; d <= 9; ++d) {
    int min_row = min_rows[d];
    int max_row = max_rows[d];
    int min_col = min_cols[d];
    int max_col = max_cols[d];
    int area = 0;
    for (int r = 0; r < n; ++r) {
      vector<int>& c = cols[d][r];
      if (c.size() == 0) {
        continue;
      }

      int w1 = c.back(), w2 = n - c[0] - 1;
      int h1 = r - min_row, h2 = max_row - r;
      area = max({area, w1 * h1, w2 * h1, w1 * h2, w2 * h2});
      // cout << "d=" << d << ", w1=" << w1 << ",w2=" << w2 << ",h1=" << h1 << ",h2=" << h2 << ",area=" << area << endl; 
      if (c.size() > 1) {
        int w = c.back() - c[0];
        h1 = r, h2 = n - r - 1;
        area = max({area, w * h1, w * h2});
      }
    }

    for (int c = 0; c < n; ++c) {
      vector<int>& r = rows[d][c];
      if (r.size() == 0) {
        continue;
      }

      int w1 = r.back(), w2 = n - r[0] - 1;
      int h1 = c - min_col, h2 = max_col - c;
      area = max({area, w1 * h1, w2 * h1, w1 * h2, w2 * h2});
      // cout << "d=" << d << ", w1=" << w1 << ",w2=" << w2 << ",h1=" << h1 << ",h2=" << h2 << ",area=" << area << endl; 
      if (r.size() > 1) {
        int w = r.back() - r[0];
        h1 = c, h2 = n - c - 1;
        area = max({area, w * h1, w * h2});
      }
    }

    ans[d] = area;
  }

  for (int d = 0; d <= 9; ++d) {
    cout << ans[d] << " ";
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
