#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  const int k = 2;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = i+2, r = n-1;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (a[mid] - a[i] <= k) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    if (idx >= 0) {
      i64 len = idx-i;
      ans += (len-1) * len / 2;
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
