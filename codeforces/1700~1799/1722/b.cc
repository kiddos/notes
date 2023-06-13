#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> grid(2);
  cin >> grid[0] >> grid[1];
  for (char& ch : grid[0]) {
    if (ch == 'G' || ch == 'B') {
      ch = 'X';
    }
  }
  for (char& ch : grid[1]) {
    if (ch == 'G' || ch == 'B') {
      ch = 'X';
    }
  }
  if (grid[0] == grid[1]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
