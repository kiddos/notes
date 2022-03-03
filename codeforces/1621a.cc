#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k) {
  if (k > (n+1) / 2) {
    cout << -1 << '\n';
    return;
  }

  vector<string> board(n, string(n, '.'));
  for (int i = 0; i < n && k > 0; i+= 2, --k) {
    board[i][i] = 'R';
  }
  for (int i = 0; i < n; ++i) {
    cout << board[i] << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, k = 0;
    cin >> n >> k;
    solve(n, k);
  }
  cout << flush;
  return 0;
}
