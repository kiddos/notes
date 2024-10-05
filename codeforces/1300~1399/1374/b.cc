#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> f;
  int x = n;
  int f2 = 0;
  while (x % 2 == 0) {
    x /= 2;
    f2++;
  }
  int f3 = 0;
  while (x % 3 == 0) {
    x /= 3;
    f3++;
  }

  if (x != 1) {
    cout << "-1" << endl;
    return;
  }
  if (f2 > f3) {
    cout << "-1" << endl;
    return;
  }
  int mul2 = f3 - f2;
  int ans = mul2;
  f2 += mul2;
  ans += f3;
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
