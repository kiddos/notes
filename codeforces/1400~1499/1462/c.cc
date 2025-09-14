#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0;
  cin >> x;
  string ans;
  for (int d = 9; d >= 1; --d) {
    if (d <= x) {
      x -= d;
      ans.push_back(d + '0');
    }
  }
  if (x > 0) {
    cout << "-1" << endl;
  } else {
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
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
