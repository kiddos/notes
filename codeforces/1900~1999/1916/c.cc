#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<i64> p = a;
  for (int i = 1; i < n; ++i) {
    p[i] = p[i-1] + a[i];
  }

  int odd = 0;
  for (int i = 0; i < n; ++i) {
    odd += a[i] % 2;
    if (i == 0) {
      cout << p[i] << " ";
    } else {
      if (odd % 3 == 1) {
        i64 ans = p[i] - odd / 3 - 1;
        cout << ans << " ";
      } else {
        i64 ans = p[i] - odd / 3;
        cout << ans << " ";
      }
    }
  }
  cout << endl;
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
