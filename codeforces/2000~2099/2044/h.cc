#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void prefix_sum(vector<vector<i64>>& p, int n) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[i][j] = p[i][j] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
    }
  }
}

i64 sum(vector<vector<i64>>& p, int r1, int c1, int r2, int c2) {
  return p[r2][c2] - p[r1-1][c2] - p[r2][c1-1] + p[r1-1][c1-1];
}

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<vector<i64>> M(n, vector<i64>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> M[i][j];
    }
  }

  vector<vector<i64>> p1(n+1, vector<i64>(n+1));
  vector<vector<i64>> p2(n+1, vector<i64>(n+1));
  vector<vector<i64>> p3(n+1, vector<i64>(n+1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      i64 k = i * n + j + 1;
      p1[i+1][j+1] = M[i][j] * k;
      p2[i+1][j+1] = M[i][j];
      p3[i+1][j+1] = M[i][j] * (i+1);
    }
  }
  prefix_sum(p1, n);
  prefix_sum(p2, n);
  prefix_sum(p3, n);

  for (int i = 0; i < q; ++i) {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    cin >> x1 >> y1 >> x2 >> y2;

    i64 k = (x1-1) * n + y1;
    i64 coef3 = n - (y2-y1 + 1);
    i64 coef2 = k - coef3 * x1 - 1;
    i64 ans = sum(p1, x1, y1, x2, y2)
      - coef2 * sum(p2, x1, y1, x2, y2)
      - coef3 * sum(p3, x1, y1, x2, y2);
    cout << "k=" << k << endl;
    cout << "coef2=" << coef2 << ", coef3=" << coef3 << endl;
    cout << ans << " ";
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
