#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a, b;
  cin >> a >> b;

  int n = a.length();
  for (int i = 1; i < n; ++i) {
    if (a[i-1] == '0' && a[i] == '1' && b[i-1] == '0' && b[i] == '1') {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
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
