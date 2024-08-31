#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l = 0, r = 0;
  cin >> l >> r;
  vector<int> c(4);
  for (int i = l; i <= r; ++i) {
    c[i % 4]++;
  }
  int ans1 = min({c[1], c[2], c[3]});
  int ans2 = min({c[0], c[1], c[3]});
  cout << max(ans1, ans2) << endl;
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
