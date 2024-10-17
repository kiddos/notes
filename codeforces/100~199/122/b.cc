#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int four = 0, seven = 0;
  for (char ch : s) {
    if (ch == '4') {
      four++;
    } else if (ch == '7') {
      seven++;
    }
  }

  if (four == 0 && seven == 0) {
    cout << "-1" << endl;
    return;
  }
  if (four >= seven) {
    cout << "4" << endl;
  } else {
    cout << "7" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
