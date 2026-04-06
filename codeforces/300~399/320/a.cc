#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int i = 0;
  while (i < n) {
    if (i+2 < n && s.substr(i, 3) == "144") {
      i += 3;
    } else if (i+1 < n && s.substr(i, 2) == "14") {
      i += 2;
    } else if (s[i] == '1') {
      i++;
    } else {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
