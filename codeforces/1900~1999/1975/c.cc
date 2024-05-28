#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int med = min(a[i-1], a[i]);
    ans = max(ans, med);
  }
  for (int i = 2; i < n; ++i) {
    vector<int> b = {a[i-2], a[i-1], a[i]};
    sort(b.begin(), b.end());
    ans = max(ans, b[1]);
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
