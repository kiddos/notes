#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// [1 5 6 6 3 4]
void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int x = *max_element(a.begin(), a.end()) + 1;
  int ans = 0;
  int l = 1, r = n-2;
  while (l < r) {
    while (l-1 >= 0 && l < n && a[l] != a[l-1]) l++;
    while (r+1 < n && r >= 0 && a[r] != a[r+1]) r--;

    int len = r-l + 1;
    // cout << len << " -> "  << l << " , " << r << endl;
    if (len <= 0) {
      break;
    } else if (len == 1) {
      a[l] = x++;
      ans++;
      break;
    } else if (len == 2) {
      a[l] = a[l+1] = x++;
      ans++;
      break;
    } else if (len == 3) {
      a[l] = a[l+1] = x++;
      a[r] = a[r-1] = x++;
      ans += 2;
      break;
    } else {
      a[l] = a[l+1] = x++;
      a[r] = a[r-1] = x++;
      ans += 2;
      l++;
      r--;
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
