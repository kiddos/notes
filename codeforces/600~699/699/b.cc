#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  int total = 0;
  vector<int> rows(n), cols(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '*') {
        total++;
        rows[i]++;
        cols[j]++;
      }
    }
  }

  if (total == 0) {
    cout << "YES" << endl;
    cout << "1 1" << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int cover = rows[i] + cols[j];
      if (s[i][j] == '*') {
        cover--;
      }
      if (cover == total) {
        cout << "YES" << endl;
        cout << i+1 << " " << j+1 << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
