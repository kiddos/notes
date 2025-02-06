#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> a(6);
  cin >> a[1] >> a[2] >> a[4] >> a[5];

  auto count = [&]() -> int {
    int ans = 0;
    for (int i = 3; i <= 5; ++i) {
      ans += (a[i-2] + a[i-1] == a[i]);
    }
    return ans;
  };
  a[3] = a[1] + a[2];
  int ans = count();
  a[3] = a[4] - a[2];
  ans = max(ans, count());
  a[3] = a[5] - a[4];
  ans = max(ans, count());

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
