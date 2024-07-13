#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<string> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i < n; ++i) {
    int a_sum = 0, b_sum = 0;
    for (int j = 0; j < m; ++j) {
      a_sum += a[i][j] - '0';
      b_sum += b[i][j] - '0';
    }
    if (a_sum % 3 != b_sum % 3) {
      cout << "NO" << endl;
      return;
    }
  }

  for (int j = 0; j < m; ++j) {
    int a_sum = 0, b_sum = 0;
    for (int i = 0; i < n; ++i) {
      a_sum += a[i][j] - '0';
      b_sum += b[i][j] - '0';
    }
    if (a_sum % 3 != b_sum % 3) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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
