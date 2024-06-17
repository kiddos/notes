#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 c1 = 0, c2 = 0;
  for (int i = 0; i < n; ++i) {
    i64 c3 = min({c1 + a[i], abs(c1 + a[i]), c2 + a[i], abs(c2 + a[i])});
    i64 c4 = max({c1 + a[i], abs(c1 + a[i]), c2 + a[i], abs(c2 + a[i])});
    c1 = c3;
    c2 = c4;
  }
  cout << c2 << endl;
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
