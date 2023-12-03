#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  
  int shortest = n - 1 + m - 1;
  if (k < shortest) {
    cout << "NO" << endl;
    return;
  }

  int diff = k - shortest;
  if (diff % 2 == 1) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  vector<string> horizontal(n, string(m-1, 'R'));
  vector<string> vertical(n-1, string(m, 'R'));
  bool red = false;
  for (int i = 0; i < m-1; ++i) {
    horizontal[0][i] = red ? 'R' : 'B';
    red = !red;
  }
  for (int i = 0; i < n-1; ++i) {
    vertical[i].back() = red ? 'R' : 'B';
    red = !red;
  }

  if (diff > 0) {
    horizontal[1].back() = horizontal[0].back();
    vertical[0][m-2] = vertical[0][m-1];

    if (diff % 4 != 0) {
      horizontal[n-1].back() = horizontal[n-2].back() = (vertical[n-3].back() == 'R' ? 'B' : 'R');
      vertical[n-2][m-2] = vertical[n-3].back();
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m-1; ++j) {
      cout << horizontal[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << vertical[i][j] << " ";
    }
    cout << endl;
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
