#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 W = 0, H = 0;
  cin >> W >> H;
  i64 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  i64 w = 0, h = 0;
  cin >> w >> h;

  int width = x2 - x1, height = y2 - y1;
  if (width + w > W && height + h > H) {
    cout << "-1" << endl;
    return;
  }
  vector<array<i64,4>> coords = {
    {0, 0, w, h},
    {0, H-h, w, H},
    {W-w, 0, W, h},
    {W-w, H-h, W, H},
  };

  i64 ans = numeric_limits<int>::max();
  for (auto [x3, y3, x4, y4] : coords) {
    pair<int,int> bot_left = {max(x3, x1), max(y3, y1)};
    pair<int,int> top_right = {min(x4, x2), min(y4, y2)};
    int intersect_w = max(top_right.first - bot_left.first, 0);
    int intersect_h = max(top_right.second - bot_left.second, 0);
    if (intersect_w > 0 && intersect_h > 0) {
      if (x4 + width <= W) {
        ans = min(ans, abs(x4 - x1));
      }
      if (x3 - width >= 0) {
        ans = min(ans, abs(x2 - x3));
      }
      if (y4 + height <= H) {
        ans = min(ans, abs(y4 - y1));
      }
      if (y3 - height >= 0) {
        ans = min(ans, abs(y2 - y3));
      }
    } else {
      ans = 0;
      break;
    }
  }
  cout << ans << endl;
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
