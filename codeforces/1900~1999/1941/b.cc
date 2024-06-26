#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 0; i < n-2; ++i) {
    if (a[i] < 0) {
      cout << "NO" << endl;
      return;
    }

    int t = a[i];
    a[i] -= t;
    a[i+1] -= t * 2;
    a[i+2] -= t;
  }

  if (a[n-1] != 0 || a[n-2] != 0) {
    cout << "NO" << endl;
    return;
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
