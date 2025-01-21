#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0, c = 0;
  cin >> n >> a >> b >> c;
  int sum = a + b + c;
  int ans = n / sum * 3;
  n -= n / sum * sum;
  if (n > 0) {
    n -= a;
    ans++;
  }
  if (n > 0) {
    n -= b;
    ans++;
  }
  if (n > 0) {
    n -= c;
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
