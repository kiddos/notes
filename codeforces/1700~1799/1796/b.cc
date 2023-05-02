#include <bits/stdc++.h>

using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;
  if (a[0] == b[0]) {
    cout << "YES" << endl;
    cout << a[0] << "*" << endl;
  } else if (a.back() == b.back()) {
    cout << "YES" << endl;
    cout << "*" << a.back() << endl;
  } else {
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
      for (char c2 = 'a'; c2 <= 'z'; ++c2) {
        string s;
        s.push_back(c1);
        s.push_back(c2);

        if (a.find(s) != string::npos && b.find(s) != string::npos) {
          cout << "YES" << endl;
          cout << "*" << s << "*" << endl;
          return;
        }
      }
    }
    cout << "NO" << endl;
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
