#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int c = max(a[i], a[i-1]);
    int d = min(a[i], a[i-1]);
    while (d * 2 < c) {
      d *= 2;
      ans++;
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
