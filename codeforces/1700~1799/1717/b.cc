#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0, r = 0, c = 0;
  cin >> n >> k >> r >> c;
  r--;
  c--;

  vector<string> grid(n, string(n, '.'));
  int r1 = r, c1 = c;
  while (r1 > 0) {
    r1--;
    c1++;
  }
  c1 %= n;
  for (int i = 0; i < n; ++i) {
    for (int j = c1; j < n; j += k) {
      grid[i][j] = 'X';
    }
    for (int j = c1; j >= 0; j -= k) {
      grid[i][j] = 'X';
    }
    c1 = (c1-1 + n) % n;
  }

  for (string& row : grid) {
    cout << row << endl;
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
