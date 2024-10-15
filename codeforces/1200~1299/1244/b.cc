#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int ans = n;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      int left = i+1;
      int right = n-i;
      ans = max({ans, left * 2, right * 2});
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
