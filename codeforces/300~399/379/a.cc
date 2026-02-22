#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  int ans = 0;
  while (a >= b) {
    int new_candle = a / b;
    int use = new_candle * b;
    ans += use;
    a -= use;
    a += new_candle;
  }
  ans += a;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
