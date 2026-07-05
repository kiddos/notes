#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> b[i][j];
    }
  }
  int size = n + m + 1;
  vector<vector<int>> diag_a(size), diag_b(size);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int d = i+j;
      diag_a[d].push_back(a[i][j]);
      diag_b[d].push_back(b[i][j]);
    }
  }

  for (int d = 0; d < size; ++d) {
    vector<int>& a_list = diag_a[d];
    vector<int>& b_list = diag_b[d];
    sort(a_list.begin(), a_list.end());
    sort(b_list.begin(), b_list.end());
    if (a_list != b_list) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
