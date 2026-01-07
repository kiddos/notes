#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string t = "hello";
  int n = s.length();
  for (int i = 0, j = 0; i < n; ++i) {
    if (s[i] == t[j]) {
      j++;
    }
    if (j == (int)t.length()) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
