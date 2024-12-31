#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0, y = 0;
  cin >> n >> x >> y;
  x--;
  y--;

  vector<int> ans(n);
  int b = 0;
  for (int i = x; i < n; ++i, b = 1-b) {
    ans[i] = b;
  }
  for (int i = 0; i < x; ++i, b = 1-b) {
    ans[i] = b;
  }

  if (n % 2 == 1 || abs(x - y) % 2 == 0) {
    ans[x] = 2;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
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
