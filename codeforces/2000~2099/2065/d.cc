#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<i64>> a(n, vector<i64>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  vector<vector<i64>> p = a;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      p[i][j] += p[i][j-1];
    }
    reverse(p[i].begin(), p[i].end());
  }

  vector<int> indices(n);
  iota(indices.begin(), indices.end(), 0);
  sort(indices.begin(), indices.end(), [&](int i1, int i2) {
    return p[i1] > p[i2];
  });

  vector<i64> b;
  for (int r : indices) {
    for (int j = 0; j < m; ++j) {
      b.push_back(a[r][j]);
    }
  }
  vector<i64> S = b;
  int size = S.size();
  for (int i = 1; i < size; ++i) {
    S[i] += S[i-1];
  }
  i64 ans = accumulate(S.begin(), S.end(), 0LL);
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
