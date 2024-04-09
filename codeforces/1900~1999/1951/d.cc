#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;

  if (n < k) {
    cout << "NO" << endl;
    return;
  }

  if (n == k) {
    cout << "YES" << endl;
    cout << "1" << endl;
    cout << "1" << endl;
    return;
  }
  i64 single = n - (k-1);
  if (single * 2 > n) {
    cout << "YES" << endl;
    cout << "2" << endl;
    cout << single << " 1" << endl;
    return;
  }
  cout << "NO" << endl;
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
