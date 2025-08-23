#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  x--;
  string s;
  cin >> s;

  int right = n;
  for (int i = x+1; i < n; ++i) {
    if (s[i] == '#') {
      right = i;
      break;
    }
  }
  int left = -1;
  for (int i = x-1; i >= 0; --i) {
    if (s[i] == '#') {
      left = i;
      break;
    }
  }

  int build_left_first = min(n-right + 1, x+1);
  int build_right_first = min(left+2, n-x);
  // cout << build_right_first << "," << build_left_first << endl;
  int ans = max(build_left_first, build_right_first);
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
