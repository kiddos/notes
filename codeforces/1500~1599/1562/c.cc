#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  s = " " + s;
 
  int m = (n+1) / 2;
  for (int i = 1; i <= m; ++i) {
    if (s[i] == '0') {
      cout << i << " " << n << " " << i+1 << " " << n << endl;
      return;
    }
  }
  m = n / 2 + 1;
  for (int i = m; i <= n; ++i) {
    if (s[i] == '0') {
      cout << 1 << " " << i << " " << 1 << " " << i-1 << endl;
      return;
    }
  }

  // all ones
  cout << 1 << " " << n-1 << " " << 2 << " " << n << endl;
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
