#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string ans(m+1, 'B');

  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    if (a <= m / 2) {
      if (ans[a] == 'B') {
        ans[a] = 'A';
      } else {
        ans[m+1-a] = 'A';
      }
    } else {
      if (ans[m+1-a] == 'B') {
        ans[m+1-a] = 'A';
      } else {
        ans[a] = 'A';
      }
    }
  }

  ans = ans.substr(1);
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
