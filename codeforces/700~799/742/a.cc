#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int x = 8;
  int ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= 10;
    }
    n /= 2;
    x = (x * x) % 10;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
