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

  i64 diff = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] > a[i]) {
      cout << "NO" << endl;
      return;
    }

    diff = max(diff, a[i] - b[i]);
  }

  for (int i = 0; i < n; ++i) {
    a[i] = max(0LL, a[i] - diff);
    if (a[i] != b[i]) {
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
