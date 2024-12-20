#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto has_iq = [&](int idx) -> int {
    int q0 = q;
    for (int i = idx; i < n; ++i) {
      if (a[i] > q0) {
        q0--;
      }
    }
    return q0 >= 0;
  };

  int l = 0, r = n-1;
  int idx = n;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (has_iq(mid)) {
      r = mid-1;
      idx = mid;
    } else {
      l = mid + 1;
    }
  }

  string ans(n, '0');
  int q0 = q;
  for (int i = 0; i < n && q0 > 0; ++i) {
    if (i < idx) {
      if (a[i] <= q0) {
        ans[i] = '1';
      }
    } else {
      if (a[i] <= q0) {
        ans[i] = '1';
      } else {
        q0--;
        ans[i] = '1';
      }
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
