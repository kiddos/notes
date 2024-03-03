#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, X = 0;
  cin >> n >> X;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<vector<vector<int>>> dp1(n, vector<vector<int>>(n, vector<int>(X+1, n)));
  vector<vector<vector<int>>> dp2(n, vector<vector<int>>(n, vector<int>(X+1, n)));
  vector<vector<int>> right_not_x(X+1, vector<int>(n, n));
  vector<vector<int>> left_not_x(X+1, vector<int>(n, -1));
  vector<vector<int>> right_x(X+1, vector<int>(n, n));
  vector<vector<int>> left_x(X+1, vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      for (int x = 1; x <= X; ++x) {
        left_x[x][i] = left_x[x][i-1];
      }
    }
    left_x[a[i]][i] = i;
  }
  for (int i = n-1; i >= 0; --i) {
    if (i+1 < n) {
      for (int x = 1; x <= X; ++x) {
        right_x[x][i] = right_x[x][i+1];
      }
    }
    right_x[a[i]][i] = i;
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      for (int x = 1; x <= X; ++x) {
        left_not_x[x][i] = left_not_x[x][i-1];
      }
    }
    for (int x = 1; x <= X; ++x) {
      if (a[i] != x) {
        left_not_x[x][i] = i;
      }
    }
  }
  for (int i = n-1; i >= 0; --i) {
    if (i+1 < n) {
      for (int x = 1; x <= X; ++x) {
        right_not_x[x][i] = right_not_x[x][i+1];
      }
    }
    for (int x = 1; x <= X; ++x) {
      if (a[i] != x) {
        right_not_x[x][i] = i;
      }
    }
  }

  for (int l = n-1; l >= 0; --l) {
    for (int r = l; r < n; ++r) {
      int len = r-l+1;
      for (int x = 1; x <= X; ++x) {
        if (len == 1) {
          if (a[l] == x) {
            dp1[l][r][x] = 0;
            dp2[l][r][x] = 1;
          } else {
            dp1[l][r][x] = 1;
            dp2[l][r][x] = 0;
          }
        } else {
          int l2 = right_not_x[x][l];
          int r2 = left_not_x[x][r];
          int l3 = right_x[x][l];
          int r3 = left_x[x][r];

          auto compute = [&]() {
            if (l2 > r2) {
              dp1[l][r][x] = 0;
            } else {
              for (int i = l2; i < r2; ++i) {
                dp1[l][r][x] = min(dp1[l][r][x], dp1[l][i][x] + dp1[i+1][r][x]);
              }
              dp1[l][r][x] = min(dp1[l][r][x], dp2[l2][r2][x]+1);
            }
          };
          auto compute_not = [&]() {
            if (l3 > r3) {
              // cout << "l=" << l << ", r=" << r << " l3=" << l3 << ", r3=" << r3 << ",x=" << x << endl;
              dp2[l][r][x] = 0;
            } else {
              for (int i = l3; i < r3; ++i) {
                dp2[l][r][x] = min(dp2[l][r][x], dp2[l][i][x] + dp2[i+1][r][x]);
              }
              for (int y = 1; y <= X; ++y) {
                if (y != x) {
                  dp2[l][r][x] = min(dp2[l][r][x], dp1[l3][r3][y]);
                }
              }
            }
          };

          int len1 = r2-l2+1;
          int len2 = r3-l3+1;
          if (len1 < len2) {
            compute();
            compute_not();
          } else {
            compute_not();
            compute();
          }
        }
      }
    }
  }

  // cout << endl;
  // for (int x = 1; x <= X; ++x) {
  //   for (int l = 0; l < n; ++l) {
  //     for (int r = 0; r < n; ++r) {
  //       cout << dp1[l][r][x] << " ";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }
  //
  // for (int x = 1; x <= X; ++x) {
  //   for (int l = 0; l < n; ++l) {
  //     for (int r = 0; r < n; ++r) {
  //       cout << dp2[l][r][x] << " ";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }

  int ans = n;
  for (int x = 1; x <= X; ++x) {
    // cout << dp1[0][n-1][x] << endl;
    ans = min(ans, dp1[0][n-1][x]);
  }
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
