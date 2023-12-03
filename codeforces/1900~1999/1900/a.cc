#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int empty = 0;
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (i == n || s[i] != '.') {
      if (empty == 0) continue;

      if (empty <= 2) {
        ans += empty;
        empty = 0;
      } else {
        ans = 2;
        break;
      }
    } else {
      empty++;
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
