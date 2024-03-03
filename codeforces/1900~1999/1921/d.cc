#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  i64 ans = 0;
  int l = 0, r = n-1;
  int p1 = 0, p2 = m-1;
  while (l <= r) {
    i64 d1 = abs(a[l] - b[p2]);
    i64 d2 = abs(a[r] - b[p1]);
    if (d1 >= d2) {
      ans += d1;
      l++;
      p2--;
    } else {
      ans += d2;
      r--;
      p1++;
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
