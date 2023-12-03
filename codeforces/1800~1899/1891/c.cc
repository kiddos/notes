#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  i64 x = 0;
  i64 ans = 0;
  int l = 0, r = n-1;
  while (l < r) {
    while (l < r && x < a[r]) {
      i64 require = a[r] - x;
      i64 op1 = min(a[l], require);
      a[l] -= op1;
      x += op1;
      ans += op1;
      if (a[l] == 0) l++;
    }
    if (x == a[r]) {
      // op2
      ans++;
      r--;
      x = 0;
    } else {
      break;
    }
  }
  if (l == r) {
    // 1 horde left
    i64 h = a[l];
    // cout << "x=" << x << ", h=" << h << endl;
    if (h == 1) {
      ans++;
    } else {
      i64 a = (h - x) / 2;
      ans += a;
      h -= (x + a + a);
      ans++;
      ans += h;
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
