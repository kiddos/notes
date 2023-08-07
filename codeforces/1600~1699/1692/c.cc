#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);

  vector<string> board(8);
  for (int i = 0; i < 8; ++i) {
    cin >> board[i];
  }

  for (int r = 1; r < 7; ++ r) {
    for (int c = 1; c < 7 ; ++c) {
      if (board[r][c] == '#' && board[r-1][c-1] == '#' && board[r-1][c+1] == '#' && board[r+1][c-1] == '#' && board[r+1][c+1] == '#') {
        cout << r+1 << " " << c+1 << endl;
        return;
      }
    }
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
