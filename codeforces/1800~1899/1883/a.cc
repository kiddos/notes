#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string position = "1234567890";
  s = "1" + s;
  int n = s.length();
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int a = position.find(s[i-1]);
    int b = position.find(s[i]);
    ans += abs(a-b) + 1;
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
