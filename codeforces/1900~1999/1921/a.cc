#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<pair<int,int>> coords;
  for (int i = 0; i < 4; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    coords.emplace_back(x, y);
  }
  sort(coords.begin(), coords.end());
  i64 w = coords[1].second - coords[0].second;
  i64 h = coords[2].first - coords[1].first;
  cout << w * h << endl;
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
