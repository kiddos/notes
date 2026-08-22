#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> d(3);
  for (int i = 0; i < 3; ++i) {
    cin >> d[i];
  }

  int ans = min(d[0], d[1] + d[2]) + min(d[2], d[0] + d[1]) + min(d[1], d[2] + d[0]);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
