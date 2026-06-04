#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<int> y(n);
  for (int i = 0; i < n; ++i) {
    cin >> y[i];
  }
  vector<pair<int,int>> points;
  for (int i = 0; i < n; ++i) {
    points.push_back({x[i], y[i]});
  }
  sort(points.begin(), points.end());
  vector<int> c(n);
  int ans = 0;
  for (int i = n-1; i >= 0; --i) {
    int l = i, r = n-1;
    int idx = i;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (points[mid].first <= points[i].first + k) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    int can_catch = idx-i+1;
    c[i] = can_catch;
    if (i+1 < n) {
      c[i] = max(c[i], c[i+1]);
    }
    ans = max(ans, can_catch + (idx+1 < n ? c[idx+1] : 0));
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
