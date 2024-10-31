#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, r = 0;
  cin >> n >> r;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  int single = 0;
  for (int i = 0; i < n; ++i) {
    int pairs = a[i] / 2;
    ans += pairs * 2;
    single += a[i] % 2;
    r -= pairs;
  }

  while (single > 0) {
    if ((r-1) * 2 >= single - 1) {
      r--;
      single--;
      ans++;
    } else {
      break;
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
