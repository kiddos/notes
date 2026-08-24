#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }

  vector<pair<i64,i64>> ans;
  for (int i = 0; i < m; ++i) {
    int l = 1, r = n;
    int index = 1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (p[mid] >= b[i]) {
        r = mid-1;
        index = mid;
      } else {
        l = mid+1;
      }
    }
    i64 dorm = index;
    i64 room = b[i] - p[index-1];
    ans.push_back({dorm, room});
  }

  for (auto [dorm, room] : ans) {
    cout << dorm << " " << room << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
