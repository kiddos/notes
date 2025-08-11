#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  i64 total = 0;
  for (int i = 0; i < n; ++i) {
    int remove_one = max(b[i] - d[i], 0);
    if (remove_one) {
      int ops = remove_one + a[i];
      total += ops;
    } else {
      int remove_zero = max(a[i] - c[i], 0);
      total += remove_zero;
    }
  }
  cout << total << endl;
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
