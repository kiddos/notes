#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int y = 0, w = 0;
  cin >> y >> w;
  int count = 6 - max(y, w) + 1;
  int g = gcd(6, count);
  cout << count / g << "/" << 6 / g << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
