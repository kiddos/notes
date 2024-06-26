#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int m = n / 2;
  for (int i = 0; i < m; ++i) {
    if (s[i] == '0') {
      cout << i+1 << " " << n << " " << i+2 << " " << n << endl;
      return;
    }
  }
  for (int i = m; i < n; ++i) {
    if (s[i] == '0') {
      cout << 1 << " " << i+1 << " " << 1 << " " << i << endl;
      return;
    }
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
