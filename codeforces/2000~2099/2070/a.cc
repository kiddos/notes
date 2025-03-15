#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int x = 0;

void precompute() {
  for (int i = 0; i < 15; ++i) {
    if (i % 3 == i % 5) {
      x++;
    }
  }
}

void solve() {
  i64 n = 0;
  cin >> n;
  i64 ans = n / 15 * x;
  n %= 15;
  for (int i = 0; i <= n; ++i) {
    if (i % 3 == i % 5) {
      ans++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
