#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// let say we perform k step,
// we can notice p + q = (k + 1) * k / 2
// we want to find the largest k such that (k + 1) * k / 2 <= (x + y)
// this should be optimal

void solve() {
  i64 x = 0, y = 0;
  cin >> x >> y;

  i64 l = 0, r = 100000000;
  i64 k = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 sum = (mid+1) * (mid) / 2;
    if (sum <= x + y) {
      k = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }

  // cout << "k=" << k << endl;

  i64 m = (k + 1) * k / 2;
  i64 p1 = x, q1 = m - p1;
  i64 q2 = y, p2 = m - q2;

  i64 cx1 = (p1+p2) / 2;
  i64 cy1 = m - cx1;
  i64 cy2 = (q1+q2) / 2;
  i64 cx2 = m - cy2;

  vector<pair<i64,i64>> centers;
  centers.emplace_back(cx1, cy1);
  centers.emplace_back(cx1-1, cy1+1);
  centers.emplace_back(cx1+1, cy1-1);
  centers.emplace_back(cx2, cy2);
  centers.emplace_back(cx2-1, cy2+1);
  centers.emplace_back(cx2+1, cy2-1);

  pair<i64,i64> best;
  i64 best_dist = numeric_limits<i64>::max();
  for (auto [cx, cy] : centers) {
    if (cx < 0) {
      cx = 0;
      cy = m;
    }
    if (cy < 0) {
      cy = 0;
      cx = m;
    }
    i64 dx = cx - x;
    i64 dy = cy - y;
    i64 d = dx * dx + dy * dy;
    if (d < best_dist) {
      best_dist = d;
      best = {cx, cy};
    }
  }

  // cout << best.first << " " << best.second << endl;

  string ans;
  for (int i = k; i >= 1; --i) {
    if (best.first >= i) {
      ans.push_back('X');
      best.first -= i;
    } else {
      ans.push_back('Y');
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
