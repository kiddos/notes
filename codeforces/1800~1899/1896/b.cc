#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int b = 0;
  int ans = 0;
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == 'B') {
      b++;
    } else if (s[i] == 'A') {
      ans += b;
      b = min(b, 1);
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
