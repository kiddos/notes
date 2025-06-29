#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  if (n == 1) {
    cout << "1" << endl;
    return;
  }

  multiset<int> xs, ys;
  for (int i = 0; i < n; ++i) {
    xs.insert(x[i]);
    ys.insert(y[i]);
  }

  i64 ans = numeric_limits<i64>::max();
  for (int i = 0; i < n; ++i) {
    xs.erase(xs.find(x[i]));
    ys.erase(ys.find(y[i]));

    i64 max_x = *xs.rbegin();
    i64 min_x = *xs.begin();
    i64 max_y = *ys.rbegin();
    i64 min_y = *ys.begin();
    i64 w = max_x - min_x + 1;
    i64 h = max_y - min_y + 1;
    i64 area = w * h;
    if (area == n-1) {
      i64 area1 = (w+1) * h;
      i64 area2 = w * (h+1);
      ans = min(ans, min(area1, area2));
    } else {
      ans = min(ans, area);
    }

    xs.insert(x[i]);
    ys.insert(y[i]);
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
