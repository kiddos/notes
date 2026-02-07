#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;

  bool non_zero = false;
  for (char& ch : s) {
    char ch2 = '9' - ch + '0';
    if (non_zero || ch2 != '0') {
      if (ch2 < ch) {
        ch = ch2;
      }
    }

    if (ch != '0') {
      non_zero = true;
    }
  }
  cout << s << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
