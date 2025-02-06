#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, l = 0, r = 0;
  cin >> n >> l >> r;
  vector<int> left(n+1), right(n+1);
  for (int i = 0; i < l; ++i) {
    int sock = 0;
    cin >> sock;
    left[sock]++;
  }
  for (int i = 0; i < r; ++i) {
    int sock = 0;
    cin >> sock;
    right[sock]++;
  }

  // greedy match left and right with same color
  for (int c = 1; c <= n; ++c) {
    int match = min(left[c], right[c]);
    left[c] -= match;
    right[c] -= match;
  }

  // need to make the count of each side same
  // greedy match same side with same color
  auto change_side = [&](vector<int>& socks, int limit) -> int {
    int change = 0;
    for (int c = 1; c <= n; ++c) {
      int pairs = min(socks[c] / 2, limit);
      change += pairs;
      socks[c] -= pairs * 2;
      limit -= pairs;
    }
    return change;
  };

  int left_total = accumulate(left.begin(), left.end(), 0);
  int right_total = accumulate(right.begin(), right.end(), 0);
  int diff = abs(left_total - right_total);
  int ans = 0;
  if (left_total > right_total) {
    ans += change_side(left, diff / 2);
  } else if (right_total > left_total) {
    ans += change_side(right, diff / 2);
  }

  left_total = accumulate(left.begin(), left.end(), 0);
  right_total = accumulate(right.begin(), right.end(), 0);

  // change the color for 1 side
  int change_color = min(left_total, right_total);
  ans += change_color;
  left_total -= change_color;
  right_total -= change_color;

  // the rest of the sock are all on same side, and are all different color
  // so to pair them up, each will require 1 change (change side/change color)
  ans += max(left_total, right_total);

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
