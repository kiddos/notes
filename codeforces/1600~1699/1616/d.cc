#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int x = 0;
  cin >> x;
  for (int i = 1; i <= n; ++i) a[i] -= x;

  int remove = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    int len = i-j+1;
    if ((len >= 2 && a[i] + a[i-1] < 0) || (len >= 3 && a[i] + a[i-1] + a[i-2] < 0)) {
      remove ++;
      j = i+1;
    }
  }

  int ans = n - remove;
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
