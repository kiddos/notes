#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 ans = 0;
  i64 p = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] >= a[i-1]) {
      i64 sub = 0;
      while (p-sub-1 >= 0 && a[i-1] * (1LL << (sub+1)) <= a[i]) {
        sub++;
      }
      p -= sub;
      ans += p;
    } else {
      i64 add = 0;
      while (a[i] * (1LL << add) < a[i-1]) {
        add++;
      }
      p += add;
      ans += p;
    }
    // cout << "p=" << p << endl;
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
