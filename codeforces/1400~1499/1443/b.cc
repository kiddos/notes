#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  string s;
  cin >> s;
  int n = s.length();
  int last = -1;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      if (last >= 0 && i - last > 1) {
        int middle = i - last - 1;
        ans += min(a, middle * b);
      }

      if (last < 0) {
        ans += a;
      }
      last = i;
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
