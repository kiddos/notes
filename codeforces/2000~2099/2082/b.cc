#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int max_x(int x, int n, int m) {
  while (x > 0 && n > 0) {
    x /= 2;
    n--;
  }
  while (x > 1 && m > 0) {
    x = (x+1) / 2;
    m--;
  }
  return x;
}

int min_x(int x, int n, int m) {
  while (x > 1 && m > 0) {
    x = (x+1) / 2;
    m--;
  }
  while (x > 0 && n > 0) {
    x /= 2;
    n--;
  }
  return x;
}

void solve() {
  int x = 0, n = 0, m = 0;
  cin >> x >> n >> m;

  int ans1 = min_x(x, n, m);
  int ans2 = max_x(x, n, m);
  cout << ans1 << " " << ans2 << endl;
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
