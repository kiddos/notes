#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, x = 0, y = 0;
  cin >> a >> x >> y;
  if (x > y) {
    swap(x, y);
  }

  if (a >= x && a <= y) {
    cout << "NO" << endl;
  } else{
    cout << "YES" << endl;
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
