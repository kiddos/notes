#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0, y = 0;
  cin >> n >> x >> y;

  vector<int> a(n+1, 1);
  for (int i = x+1; i <= n; i += 2) {
    a[i] = -1;
  }
  for (int i = y - 1; i >= 1; i -= 2) {
    a[i] = -1;
  }

  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
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
