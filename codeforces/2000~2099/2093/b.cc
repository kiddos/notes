#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int last = n-1;
  while (last >= 0 && s[last] == '0') {
    last--;
  }
  int ans = n-last-1;
  for (int i = last-1; i >= 0; --i) {
    if (s[i] != '0') {
      ans++;
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
