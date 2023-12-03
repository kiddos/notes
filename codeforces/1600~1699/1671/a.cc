#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && s[j] == s[i]) {
      j++;
    }

    int len = j-i;
    if (len < 2) {
      cout << "NO" << endl;
      return;
    }

    i = j;
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
