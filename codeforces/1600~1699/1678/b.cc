#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && s[j] == s[i]) {
      j++;
    }

    int len = j - i;
    if (len % 2 == 1) {
      s[j-1] = s[j-1] == '0' ? '1' : '0';
      i = j-1;
      ans++;
    } else {
      i = j;
    }
  }

  cout << ans << endl;
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
