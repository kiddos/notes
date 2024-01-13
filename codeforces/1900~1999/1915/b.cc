#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> square(3);
  for (int i = 0; i < 3; ++i) cin >> square[i];

  for (int i = 0; i < 3; ++i) {
    int sum = 0;
    bool need_answer = false;
    for (int j = 0; j < 3; ++j) {
      if (square[i][j] == 'A') {
        sum += 1;
      } else if (square[i][j] == 'B') {
        sum += 2;
      } else if (square[i][j] == 'C') {
        sum += 3;
      } else if (square[i][j] == '?') {
        need_answer = true;
      }
    }

    if (need_answer) {
      int c = 6 - sum;
      cout << (char)('A' + c - 1) << endl;
      return;
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
