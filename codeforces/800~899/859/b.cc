#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  int side = 1;
  while (side * side < n) {
    side++;
  }
  i64 row = (n + side - 1) / side;
  i64 ans = (row + side) * 2;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
