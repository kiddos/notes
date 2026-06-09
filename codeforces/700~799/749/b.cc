#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> x(3), y(3);
  for (int i = 0; i < 3; ++i) {
    cin >> x[i] >> y[i];
  }

  set<pair<int,int>> original;
  for (int i = 0; i < 3; ++i) {
    original.insert({x[i], y[i]});
  }

  set<pair<int,int>> ans;
  for (int i1 = 0; i1 < 3; ++i1) {
    for (int i2 = i1+1; i2 < 3; ++i2) {
      int dx = x[i1] - x[i2];
      int dy = y[i1] - y[i2];
      int i3 = 3 - i1 - i2;
      int x4 = x[i3] + dx;
      int y4 = y[i3] + dy;
      int x5 = x[i3] - dx;
      int y5 = y[i3] - dy;
      if (!original.count({x4, y4})) {
        ans.insert({x4, y4});
      }
      if (!original.count({x5, y5})) {
        ans.insert({x5, y5});
      }
    }
  }

  cout << ans.size() << endl;
  for (auto [xi, yi] : ans) {
    cout << xi << " " << yi << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
