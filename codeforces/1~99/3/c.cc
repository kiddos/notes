#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<string> s(3);
  for (int i = 0; i < 3; ++i) {
    cin >> s[i];
  }
  int x = 0, o = 0, empty =0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (s[i][j] == 'X') {
        x++;
      } else if (s[i][j] == '0') {
        o++;
      } else if (s[i][j] == '.') {
        empty++;
      }
    }
  }

  // cout << "x=" << x << ",o=" << o << endl;

  if (x < o) {
    cout << "illegal" << endl;
    return;
  }

  if (x > o+1) {
    cout << "illegal" << endl;
    return;
  }

  int x_win = 0, o_win = 0;
  for (int i = 0; i < 3; ++i) {
    if (s[i] == "XXX") {
      x_win++;
    } else if (s[i] == "000") {
      o_win++;
    }
    if (s[0][i] == 'X' && s[1][i] == 'X' && s[2][i] == 'X') {
      x_win++;
    } else if (s[0][i] == '0' && s[1][i] == '0' && s[2][i] == '0') {
      o_win++;
    }
  }
  if (s[0][0] == 'X' && s[1][1] == 'X' && s[2][2] == 'X') {
    x_win++;
  } else if (s[0][0] == '0' && s[1][1] == '0' && s[2][2] == '0') {
    o_win++;
  }
  if (s[0][2] == 'X' && s[1][1] == 'X' && s[2][0] == 'X') {
    x_win++;
  } else if (s[0][2] == '0' && s[1][1] == '0' && s[2][0] == '0') {
    o_win++;
  }

  // cout << "x win =" << x_win << ",o win=" << o_win << endl;

  if (x_win && o_win) {
    cout << "illegal" << endl;
    return;
  }

  if (x_win) {
    if (x > o) {
      cout << "the first player won" << endl;
    } else {
      cout << "illegal" << endl;
    }
    return;
  }
  if (o_win) {
    if (x == o) {
      cout << "the second player won" << endl;
    } else {
      cout << "illegal" << endl;
    }
    return;
  }

  if (empty == 0) {
    cout << "draw" << endl;
    return;
  }

  if (x > o) {
    cout << "second" << endl;
  } else {
    cout << "first" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
