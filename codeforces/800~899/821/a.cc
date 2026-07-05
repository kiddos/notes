#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  vector<set<int>> cols(n);
  vector<set<int>> rows(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cols[j].insert(a[i][j]);
      rows[i].insert(a[i][j]);
    }
  }

  auto exists = [&](int r, int c) -> bool {
    int target = a[r][c];
    for (int j = 0; j < n; ++j) {
      if (cols[c].count(target - a[r][j])) {
        return true;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (rows[r].count(target - a[i][c])) {
        return true;
      }
    }
    return false;
  };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 1) {
        continue;
      }
      if (!exists(i, j)) {
        cout << "No" << endl;
        return;
      }
    }
  }
  cout << "Yes" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
