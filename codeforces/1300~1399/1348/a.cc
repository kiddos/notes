#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int half = n / 2;
  int a = 1<<n;
  int b = 0;
  for (int i = 0, bit = n-1; i < half; ++i, --bit) {
    b |= (1<<bit);
  }
  for (int i = 0, bit = n-half-1; i < half-1; ++i, --bit) {
    a |= (1<<bit);
  }
  int ans = a - b;
  cout << ans << endl;
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
