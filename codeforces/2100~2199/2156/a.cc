#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  i64 ans = 0;
  while (n > 2) {
    int m1 = n / 3;
    int m3 = m1;
    int left = n - m1 * 3;
    if (left) {
      m3++;
      left--;
    }
    if (left) {
      m3++;
      left--;
    }
    ans += m1;
    n = m3;
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
