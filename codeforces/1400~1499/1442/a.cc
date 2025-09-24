#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int val = a[0];
  a[0] = 0;
  for (int i = 1; i < n; ++i) {
    val = min({val, a[i], max(a[i] - a[i-1], 0)});
    a[i] -= val;
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;

  for (int i = 0; i+1 < n; ++i) {
    if (a[i] > a[i+1]) {
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
