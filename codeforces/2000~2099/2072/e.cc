#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0;
  cin >> k;

  vector<pair<int,int>> ans;
  ans.emplace_back(0, 0);
  vector<pair<int,int>> delta = {{0, 1}, {1, 0}};
  int d = 0;

  while (k > 0) {
    i64 add = 1;
    while (k >= add) {
      auto [x, y] = ans.back();
      auto [dx, dy] = delta[d%2];
      ans.emplace_back(x + dx, y + dy);
      k -= add;
      add++;
    }
    d++;
  }

  cout << ans.size() << endl;
  for (auto [x, y] : ans) {
    cout << x << " " << y << endl;
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
