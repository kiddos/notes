#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  string r(s.rbegin(), s.rend());
  string ans = s + r;
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
