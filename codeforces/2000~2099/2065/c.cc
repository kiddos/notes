#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());

  vector<i64> c = a;
  c[0] = min(a[0], b[0] - a[0]);
  for (int i = 1; i < n; ++i) {
    // b[i] - a[i] >= c[i-1]
    // => b[i] >= c[i-1] + a[i]
    i64 target = c[i-1] + a[i];
    auto it = lower_bound(b.begin(), b.end(), target);
    if (it != b.end()) {
      if (c[i] >= c[i-1]) {
        c[i] = min(c[i], *it - c[i]);
      } else {
        c[i] = *it - c[i];
      }
    }

    // for (int i = 0; i < n; ++i) {
    //   cout << c[i] << " ";
    // }
    // cout << endl;
    if (c[i-1] > c[i]) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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
