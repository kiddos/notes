#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int allin = 0, folded = 0, in = 0;
  for (char ch : s) {
    if (ch == 'A') {
      allin++;
    } else if (ch == 'F') {
      folded++;
    } else if (ch == 'I') {
      in++;
    }
  }

  if (in > 1) {
    cout << "0" << endl;
  } else if (in == 1) {
    cout << "1" << endl;
  } else {
    cout << allin << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
