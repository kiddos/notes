#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  // 9 -> 1001
  // 8 -> 1000
  // 10011000
  // need a new 8 at the end at 5, 9, 13
  if (n == 1) {
    cout << "8" << endl;
  } else {
    int eight = (n + 3) / 4;
    int nine = n - eight;
    string ans = string(nine, '9') + string(eight, '8');
    cout << ans << endl;
  }
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
