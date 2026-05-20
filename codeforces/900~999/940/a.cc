#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, d = 0;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = n;
  for (int i = 0; i < n; ++i) {
    int l = i, r = n-1;
    int idx = l;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (a[mid] - a[i] <= d) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    int size = idx-i+1;
    int remove = n-size;
    ans = min(ans, remove);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
