#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int current = 1;
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      current++;
    } else {
      current = 1;
    }
    ans = max(ans, current);
  }

  cout << ans+1 << endl;
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
