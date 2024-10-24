#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  
  if (n % 2 == 1) {
    cout << "NO" << endl;
    return;
  }

  int move = 0;
  int b = 0;
  int open = 0, close = 0;
  for (char ch : s) {
    if (ch == '(') {
      open++;
      b++;
    } else if (ch == ')') {
      close++;
      b--;
    }

    if (b < 0) {
      b = 0;
      move++;
    }
  }

  if (move <= 1 && open == close) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
