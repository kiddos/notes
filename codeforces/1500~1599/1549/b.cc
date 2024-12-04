#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s2[i] == '1') {
      if (s1[i] == '0') {
        ans++;
      } else if (i > 0 && s1[i-1] == '1') {
        s1[i-1] = '0';
        ans++;
      } else if (i+1 < n && s1[i+1] == '1') {
        s1[i+1] = '0';
        ans++;
      }
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
