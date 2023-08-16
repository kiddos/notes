#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int evens = 0;
  int to_odd = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    int op = 0;
    while (x % 2 == 0) {
      x /= 2;
      op++;
    }
    to_odd = min(to_odd, op);

    evens += a[i] % 2 == 0;
  }

  int ans = to_odd;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      ans++;
    }
  }
  if (evens == n) {
    ans--;
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
