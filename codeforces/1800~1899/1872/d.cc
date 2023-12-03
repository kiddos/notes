#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, x = 0, y = 0;
  cin >> n >> x >> y;
  
  i64 l = x * y / gcd(x, y) ;
  i64 x_count = n / x - n / l;
  i64 y_count = n / y - n / l;

  i64 ans = (n-x_count+1 + n)  * x_count / 2 - (1 + y_count -1 + 1) * y_count / 2;
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
