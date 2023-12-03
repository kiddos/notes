#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, a = 0, b = 0;
  cin >> n >> k >> a >> b;

  vector<array<i64,2>> coord;
  for (int i = 0; i < n; ++i) {
    i64 x = 0, y = 0;
    cin >> x >> y;
    coord.push_back({x, y});
  }

  if (a <= k && b <= k) {
    // both major
    cout << "0" << endl;
    return;
  }

  const i64 INF = numeric_limits<i64>::max();
  i64 cost_a = INF;
  i64 cost_b = INF;
  for (int i = 0; i < k; ++i) {
    i64 dx = coord[a-1][0] - coord[i][0];
    i64 dy = coord[a-1][1] - coord[i][1];
    i64 cost = abs(dx) + abs(dy);
    cost_a = min(cost_a, cost);

    dx = coord[b-1][0] - coord[i][0];
    dy = coord[b-1][1] - coord[i][1];
    cost = abs(dx) + abs(dy);
    cost_b = min(cost_b, cost);
  }
  if (a <= k) {
    cout << cost_b << endl;
    return;
  }

  if (b <= k) {
    cout << cost_a << endl;
    return;
  }

  i64 dx = coord[a-1][0] - coord[b-1][0];
  i64 dy = coord[a-1][1] - coord[b-1][1];
  // cout << dx << " " << dy << endl;
  // cout << cost_a << " " << cost_b << endl;
  i64 ans = abs(dx) + abs(dy);
  if (cost_a < INF && cost_b < INF) {
    ans = min(ans, cost_a + cost_b);
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
