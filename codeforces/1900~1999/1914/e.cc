#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<array<i64,3>> d;
  for (int i = 0; i < n; ++i) {
    i64 if_alice = b[i] - 1;
    i64 if_bob = a[i] - 1;
    d.push_back({if_alice + if_bob, if_alice, if_bob});
  }
  sort(d.rbegin(), d.rend());

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] - b[i];
    if (i % 2 == 0) {
      ans += d[i][1];
    } else {
      ans -= d[i][2];
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
