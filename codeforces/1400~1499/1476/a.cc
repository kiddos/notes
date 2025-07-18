#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int ans = 0;
  if (n > k) {
    int x = (n + k - 1) / k;
    k = x * k;
  }

  ans = k / n;
  int m = k - ans * n;
  if (m > 0) {
    ans++;
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
