#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, c0 = 0, c1 = 0, h = 0;
  cin >> n >> c0 >> c1 >> h;
  string s;
  cin >> s;
  int ans = 0;
  for (char ch : s) {
    if (ch == '1') {
      ans += min(c1, c0 + h);
    } else if (ch == '0') {
      ans += min(c0, c1 + h);
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
