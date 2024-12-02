#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int f(const string& p) {
  int n = p.length();
  set<string> s;
  for (int len = 1; len <= n; ++len) {
    for (int i = 0; i <= n-len; ++i) {
      s.insert(p.substr(i, len));
    }
  }
  return s.size();
}

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  for (int len = 2; len <= 3; ++len) {
    for (int i = 0; i <= n-len; ++i) {
      string p = s.substr(i, len);
      if (f(p) % 2 == 0) {
        cout << p << endl;
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
