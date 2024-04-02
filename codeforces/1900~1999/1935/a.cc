#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  string r(s.rbegin(), s.rend());

  if (s <= r) {
    if (n % 2 == 0) {
      cout << s << endl;
    } else {
      cout << s + r << endl;
    }
  } else {
    if (n % 2 == 1) {
      cout << r << endl;
    } else {
      cout << r + s << endl;
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
