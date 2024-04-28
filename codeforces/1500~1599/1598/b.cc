#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int, 5>> students(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) cin >> students[i][j];
  }

  auto check = [&](int d1, int d2) -> bool {
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
      if (!students[i][d1] && !students[i][d2]) {
        return false;
      }
      c1 += students[i][d1];
      c2 += students[i][d2];
    }
    return c1 >= n / 2 && c2 >= n / 2;
  };

  for (int d1 = 0; d1 < 5; ++d1) {
    for (int d2 = d1+1; d2 < 5; ++d2) {
      if (check(d1, d2)) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
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
