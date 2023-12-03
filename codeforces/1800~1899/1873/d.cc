#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  int i = 0;
  int ans = 0;
  while (i < n) {
    if (s[i] == 'W') {
      i++;
    } else if (s[i] == 'B') {
      i += k;
      ans++;
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
