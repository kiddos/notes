#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, x = 0;
  cin >> n >> k >> x;

  if (x < k-1) {
    cout << "-1" << endl;
    return;
  }

  if (n < k) {
    cout << "-1" << endl;
    return;
  }

  int count = k;
  int base = (k-1) * k / 2;
  int left = n - count;
  int ans = base;
  if (x == k) {
    ans += left * (x-1);
  } else {
    ans += left * x;
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
