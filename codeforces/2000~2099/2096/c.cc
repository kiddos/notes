#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_beautiful(vector<int>& a, int add1, vector<int>& b, int add2) {
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    if (a[i]+add1 == b[i]+add2) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> h(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> h[i][j];
    }
  }
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  constexpr i64 inf = numeric_limits<i64>::max();
  vector<vector<i64>> dp1(n, vector<i64>(2, inf));
  dp1[0][0] = 0;
  dp1[0][1] = a[0];
  for (int i = 1; i < n; ++i) {
    for (int hire1 = 0; hire1 < 2; ++hire1) {
      for (int hire2 = 0; hire2 < 2; ++hire2) {
        if (is_beautiful(h[i-1], hire1, h[i], hire2)) {
          if (dp1[i-1][hire1] < inf) {
            dp1[i][hire2] = min(dp1[i][hire2], dp1[i-1][hire1] + hire2 * a[i]);
          }
        }
      }
    }
  }
  i64 horizontal = min(dp1.back()[0], dp1.back()[1]);
  // cout << "horizontal=" << horizontal << endl;
  if (horizontal >= inf) {
    cout << "-1" << endl;
    return;
  }

  vector<vector<i64>> dp2(n, vector<i64>(2, inf));
  dp2[0][0] = 0;
  dp2[0][1] = b[0];
  for (int j = 1; j < n; ++j) {
    vector<int> col1(n), col2(n);
    for (int i = 0; i < n; ++i) {
      col1[i] = h[i][j-1];
      col2[i] = h[i][j];
    }

    for (int hire1 = 0; hire1 < 2; ++hire1) {
      for (int hire2 = 0; hire2 < 2; ++hire2) {
        if (is_beautiful(col1, hire1, col2, hire2)) {
          if (dp2[j-1][hire1] < inf) {
            dp2[j][hire2] = min(dp2[j][hire2], dp2[j-1][hire1] + hire2 * b[j]);
          }
        }
      }
    }
  }
  i64 vertical = min(dp2.back()[0], dp2.back()[1]);
  // cout << "vertical=" << vertical << endl;

  if (vertical >= inf) {
    cout << "-1" << endl;
    return;
  }
  i64 ans = horizontal + vertical;
  cout << ans << endl;
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
