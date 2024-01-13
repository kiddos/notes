#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int x = 2023;
  for (int i = 0; i < n; ++i) {
    if (x % b[i] != 0) {
      cout << "NO" << endl;
      return;
    }
    x /= b[i];
  }

  cout << "YES" << endl;
  cout << x << " ";
  for (int i = 1; i < k; ++i) cout << "1 " << " ";
  cout << endl;
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
