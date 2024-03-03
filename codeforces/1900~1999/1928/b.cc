#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  int most_diff = n-1;
  int ans = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    int l = i+1, r = a.size()-1;
    int len = 1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (a[mid] - a[i] <= most_diff) {
        l = mid+1;
        len = mid - i + 1;
      } else {
        r = mid-1;
      }
    }

    ans = max(ans, len);
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
