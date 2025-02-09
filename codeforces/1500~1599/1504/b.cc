#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<bool> can_invert(n);
  for (int i = 0, zero = 0, one = 0; i < n; ++i) {
    zero += a[i] == '0';
    one += a[i] == '1';
    can_invert[i] = zero == one;
  }

  for (int i = n-1, x = 0; i >= 0; --i) {
    if ((a[i] ^ x) != b[i]) {
      if (can_invert[i]) {
        x ^= 1;
      } else {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
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
