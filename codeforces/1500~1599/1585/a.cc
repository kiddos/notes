#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  int ans = 1;
  int no_water = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      if (i > 0 && a[i-1]) {
        ans += 5;
      } else {
        ans++;
      }
      no_water = 0;
    } else {
      no_water++;
      if (no_water >= 2) {
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
