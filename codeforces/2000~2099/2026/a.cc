#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, y = 0, k = 0;
  cin >> x >> y >> k;

  int len = min(x, y);
  cout << "0 0 " << len << " " << len << endl;
  cout << len << " 0 0 " << len << endl;
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