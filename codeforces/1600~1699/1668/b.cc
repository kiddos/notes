#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.rbegin(), a.rend());

  i64 chair = a[0] * 2 + 1;
  for (int i = 1; i < n; ++i) {
    if (i == n-1) {
      chair += 1;
    } else {
      chair += 1 + a[i];
    }
  }
  if (chair <= m) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
