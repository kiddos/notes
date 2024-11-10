#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = n-1;
  for (int i = n-1; i >= 1; --i) {
    int l = 0, r = i-1;
    int idx = r;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (a[mid] + a[mid+1] > a[i]) {
        r = mid - 1;
        idx = mid;
      } else {
        l = mid + 1;
      }
    }
    int remove = n-i-1 + idx;
    ans = min(ans, remove);
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
