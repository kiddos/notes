#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  i64 ans = 0;
  for (int b = 1; b <= n; ++b) {
    i64 possible_a = n / b;
    i64 possible_c = n / b;
    ans += possible_a * possible_c;
  }
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
