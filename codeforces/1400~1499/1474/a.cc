#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string b;
  cin >> b;

  string a(n, ' ');
  int last = -1;
  for (int i = 0; i < n; ++i) {
    if (b[i] == '0') {
      if (last == 1) {
        a[i] = '0';
        last = 0;
      } else {
        a[i] = '1';
        last = 1;
      }
    } else if (b[i] == '1') {
      if (last == 2) {
        a[i] = '0';
        last = 1;
      } else {
        a[i] = '1';
        last = 2;
      }
    }
  }
  cout << a << endl;
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
