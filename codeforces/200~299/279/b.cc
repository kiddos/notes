#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, t = 0;
  cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = i, r = n-1;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 total = p[mid+1] - p[i];
      if (total <= t) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    if (idx >= 0) {
      int count = idx - i + 1;
      ans = max(ans, count);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
