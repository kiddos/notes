#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 2; i < n; i += 2) {
    if (a[i] % 2 != a[0] % 2) {
      cout << "NO" << endl;
      return;
    }
  }
  
  for (int i = 3; i < n; i += 2) {
    if (a[i] % 2 != a[1] % 2) {
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
