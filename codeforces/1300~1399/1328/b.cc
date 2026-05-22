#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string ans(n, 'a');
  for (int i = n-2; i >= 0; --i) {
    int count = n - i - 1;
    if (k <= count) {
      int i2 = n - k;
      ans[i] = ans[i2] = 'b';
      break;
    } else {
      k -= count;
    }
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
