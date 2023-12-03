#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n, 1);
  for (int i = 1; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  auto ok = [&](int remove) {
    for (int i = 0; i < n-remove; ++i) {
      if (a[i] >= b[i+remove]) {
        return false;
      }
    }
    return true;
  };

  int l = 0, r = n;
  int ans = n;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
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
