#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  if (m % n != 0) {
    cout << "-1" << endl;
    return;
  }

  int p = m / n;
  int ans = 0;
  while (p > 1 && p % 2 == 0) {
    p /= 2;
    ans++;
  }
  while (p > 1 && p % 3 == 0) {
    p /= 3;
    ans++;
  }
  if (p > 1) {
    cout << "-1" << endl;
    return;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
