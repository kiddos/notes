#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 1; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  vector<int> c = a;

  sort(b.begin(), b.end());

  auto ok = [&](int remove) {
    for (int i = 0; i < n-remove; ++i) {
      if (c[i] >= b[i+remove]) {
        return false;
      }
    }
    return true;
  };

  auto compute = [&](int x) -> i64 {
    c = a;
    c[0] = x;
    sort(c.begin(), c.end());

    int l = 0, r = n;
    i64 ans = n;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (ok(mid)) {
        ans = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    return ans;
  };

  auto find_next_x = [&](int op, int start) -> int {
    int l = start, r = m;
    int ans = start;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 o = compute(mid);
      if (o == op) {
        ans = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  int x = 1;
  i64 ans = 0;
  while (true) {
    i64 op = compute(x);
    int x2 = find_next_x(op, x);
    ans += op * (x2 - x + 1);
    // cout << "x=" << x << ", x2=" << x2 << ", op=" << op << endl;

    x = x2+1;
    if (x > m) {
      break;
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
