#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, a = 0, b = 0;
  cin >> n >> a >> b;

  i64 use_b = min(max(b-a, 0LL), n);
  i64 use_a = n - use_b;
  i64 ans = (b + b - use_b + 1) * use_b / 2 + use_a * a;
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
