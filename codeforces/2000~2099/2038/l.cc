#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 18, 21, 25
// 60 -> 18 + 18 + 18
//    -> 18 + 21 + 21
//    -> 18 + 18 + 21
//    -> 25 + 25
void solve() {
  int n = 0;
  cin >> n;

  int ans = n + (n + 5) / 6;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
