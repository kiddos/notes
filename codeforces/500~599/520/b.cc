#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  int ans = 0;

  while (m > n) {
    if (m % 2 == 1) {
      m++;
      ans++;
    } else {
      m /= 2;
      ans++;
    }
  }
  ans += n - m;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
