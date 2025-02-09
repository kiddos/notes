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

  vector<int> rows(n), cols(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '*') {
        rows[i] = 1;
        cols[j] = 1;
      }
    }
  }

  if (accumulate(rows.begin(), rows.end(), 0) == 1) {
    for (int i = 0; i < n; ++i) {
      if (!rows[i]) {
        rows[i] = 1;
        break;
      }
    }
  }
  if (accumulate(cols.begin(), cols.end(), 0) == 1) {
    for (int i = 0; i < n; ++i) {
      if (!cols[i]) {
        cols[i] = 1;
        break;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (rows[i] && cols[j]) {
        s[i][j] = '*';
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << s[i] << endl;
  }
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
