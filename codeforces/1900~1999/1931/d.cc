#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 x = 0, y = 0;
  cin >> n >> x >> y;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<pair<int,int>,i64> count1;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    pair<int,int> key = {(x-a[i] % x) % x, a[i] % y};
    if (count1.count(key)) {
      ans += count1[key];
    }
    count1[{a[i] % x, a[i] % y}]++;
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
