#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = 0;
  for (int i = n-2; i >= 0; --i) {
    while (a[i] >= a[i+1]) {
      a[i] /= 2;
      ans++;
      if (a[i] == 0 && a[i] >= a[i+1]) {
        cout << "-1" << endl;
        return;
      }
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
