#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  int ans = n;
  for (int i = 0, white = 0; i < n; ++i) {
    if (s[i] == 'W') {
      white++;
    }
    if (i >= k && s[i-k] == 'W') {
      white--;
    }
    if (i >= k-1) {
      ans = min(ans, white);
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
