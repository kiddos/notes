#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 1) {
    if (a[0] < k) {
      cout << k << endl;
    } else {
      cout << k-1 << endl;
    }
    return;
  }

  i64 g = 0;
  for (int i = 0; i < n; ++i) {
    g = gcd(g, a[i]);
  }
  i64 l = 0, r = 2000000000;
  i64 ans = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 contains = min((mid / g) + 1, (i64)n);
    i64 missing = mid + 1 - contains;
    // cout << "mid=" << mid << ", contains=" << contains << ", missing=" << missing << endl;
    if (missing < k) {
      ans = mid + 1;
      l = mid + 1;
    } else {
      r = mid - 1;
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
