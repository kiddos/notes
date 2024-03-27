#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int ans = numeric_limits<int>::max();
  for (int i = 1; i < n; ++i) {
    if (s[i] == 'a' && s[i-1] == 'a') {
      cout << "2" << endl;
      return;
    }
  }

  for (int i = 2; i < n; ++i) {
    if (s[i] == 'a' && s[i-1] != 'a' && s[i-2] == 'a') {
      cout << "3" << endl;
      return;
    }
  }

  for (int i = 3; i < n; ++i) {
    if (s[i] == 'a' && s[i-3] == 'a' && ((s[i-1] == 'b' && s[i-2] == 'c') || (s[i-1] == 'c' && s[i-2] == 'b'))) {
      cout << "4" << endl;
      return;
    }
  }

  for (int i = 6; i < n; ++i) {
    string s2 = s.substr(i-6, 7);
    if (s2 == "abbacca" || s2 == "accabba") {
      cout << "7" << endl;
      return;
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
