#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 1; i < n; ++i) {
    if (s[i] != '0') {
      string a = s.substr(0, i);
      string b = s.substr(i);
      if (stoi(a) < stoi(b)) {
        cout << a << " " << b << endl;
        return;
      }
    }
  }

  cout << "-1" << endl;
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
