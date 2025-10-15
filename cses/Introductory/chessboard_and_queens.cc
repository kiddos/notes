#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> board(8);
  for (int i = 0; i < 8; ++i) {
    cin >> board[i];
  }

  vector<pair<int,int>> delta = {{-1, 0}, {-1, 1}, {-1, -1}};
  auto no_queen = [&](int r, int c) -> bool {
    for (auto [dr, dc] : delta) {
      for (int i = 1; i <= 8; ++i) {
        int r2 = r + dr * i;
        int c2 = c + dc * i;
        if (r2 < 0 || r2 >= 8 || c2 < 0 || c2 >= 8) {
          break;
        }

        if (board[r2][c2] == 'Q') {
          return false;
        }
      }
    }
    return true;
  };

  auto backtrack = [&](const auto& self, int r) -> int {
    if (r == 8) {
      return 1;
    }

    int ans = 0;
    for (int c = 0; c < 8; ++c) {
      if (board[r][c] == '*') {
        continue;
      }

      if (no_queen(r, c)) {
        board[r][c] = 'Q';
        ans += self(self, r+1);
        board[r][c] = '.';
      }
    }
    return ans;
  };

  int ans = backtrack(backtrack, 0);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
