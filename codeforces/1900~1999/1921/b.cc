#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string f;
  cin >> f;
  int extra = 0, require = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != f[i]) {
      if (s[i] == '1') {
        extra++;
      } else {
        require++;
      }
    }
  }
  int move = min(extra, require);
  int ans = extra + require - move;
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
