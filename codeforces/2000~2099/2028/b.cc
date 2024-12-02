#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, b = 0, c = 0;
  cin >> n >> b >> c;

  if (b > 0) {
    i64 included = (max(n - c, 0LL) + b - 1) / b;
    i64 ans = n - included;
    cout << ans << endl;
  } else {
    i64 included = c < n ? n : 0;
    if (included == 0) {
      cout << n << endl;
    } else {
      i64 need_to_change = n-1;
      i64 can_change = c+1;
      if (can_change >= need_to_change) {
        cout << need_to_change << endl;
      } else {
        cout << "-1" << endl;
      }
    }
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
