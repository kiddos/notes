#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> board(2);
  cin >> board[0] >> board[1];
  board[0] = " " + board[0] + " ";
  board[1] = " " + board[1] + " ";

  int chips = 0;
  for (int i = 1; i <= n; ++i) {
    chips += (board[0][i] == '*');
    chips += (board[1][i] == '*');
  }

  if (chips == 1) {
    cout << "0" << endl;
    return;
  }

  vector<bool> has_chip(n+2);
  for (int i = 1; i <= n; ++i) {
    has_chip[i] = has_chip[i-1] || board[0][i] == '*' || board[1][i] == '*';
  }

  vector<vector<i64>> dp1(2, vector<i64>(n+2));
  for (int i = 1; i <= n; ++i) {
    dp1[0][i] = min(
      dp1[0][i-1] + (has_chip[i-1]) + (board[1][i] == '*'),
      dp1[1][i-1] + max((int)(has_chip[i-1]) * 2, (int)(board[1][i] == '*'))
    );
    dp1[1][i] = min(
      dp1[0][i-1] + max((int)(has_chip[i-1]) * 2, (int)(board[0][i] == '*')),
      dp1[1][i-1] + (has_chip[i-1]) + (board[0][i] == '*')
    );
  }

  // cout << "dp1:" << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << dp1[0][i] << " ";
  // }
  // cout << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << dp1[1][i] << " ";
  // }
  // cout << endl;

  fill(has_chip.begin(), has_chip.end(), false);
  for (int i = n; i >= 1; --i) {
    has_chip[i] = has_chip[i+1] || board[0][i] == '*' || board[1][i] == '*';
  }

  vector<vector<i64>> dp2(2, vector<i64>(n+2));
  for (int i = n; i >= 1; --i) {
    dp2[0][i] = min(
      dp2[0][i+1] + (has_chip[i+1]) + (board[1][i] == '*'),
      dp2[1][i+1] + max((int)(has_chip[i+1]) * 2, (int)(board[1][i] == '*'))
    );
    dp2[1][i] = min(
      dp2[0][i+1] + max((int)(has_chip[i+1]) * 2, (int)(board[0][i] == '*')),
      dp2[1][i+1] + (has_chip[i+1]) + (board[0][i] == '*')
    );
  }

  // cout << "dp2:" << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << dp2[0][i] << " ";
  // }
  // cout << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << dp2[1][i] << " ";
  // }
  // cout << endl;

  i64 ans = min({dp1[0][n], dp1[1][n], dp2[0][1], dp2[1][1]});
  for (int i = 1; i <= n; ++i) {
    i64 moves = min(
      dp1[0][i] + dp2[0][i+1] + has_chip[i+1],
      dp1[1][i] + dp2[1][i+1] + has_chip[i+1]
    );
    ans = min(ans, moves);
  }
  cout << ans << endl;
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
