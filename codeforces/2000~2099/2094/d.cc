#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string p, s;
  cin >> p >> s;
  int n = p.length(), m = s.length();
  int i = 0, j = 0;
  while (i < n) {
    int i2 = i;
    while (i2+1 < n && p[i2+1] == p[i]) {
      i2++;
    }
    int j2 = j;
    while (j2+1 < m && s[j2+1] == s[j]) {
      j2++;
    }
    int len1 = i2-i+1, len2 = j2-j+1;
    if (len2 < len1 || len2 > len1 * 2) {
      cout << "NO" << endl;
      return;
    }
    if (p[i] != s[j]) {
      cout << "NO" << endl;
      return;
    }

    i = i2+1;
    j = j2+1;
  }
  if (j < m) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
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
