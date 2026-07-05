#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string t = "heidi";
  int n = s.length();
  int m = t.length();
  for (int i = 0, j = 0; i < n; ++i) {
    if (s[i] == t[j]) {
      j++;
    }
    if (j == m) {
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
