#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(a[i] + p.back());
  }
  i64 sum = p.back();

  auto get_cyclic_shift_sum = [&](int c, i64 l, i64 r) -> i64 {
    i64 l1 = (l + c) % n, r1 = (r + c) % n;
    if (l1 <= r1) {
      return p[r1+1] - p[l1];
    } else {
      return p[n] - p[l1] + p[r1+1];
    }
  };

  for (int i = 0; i < q; ++i) {
    i64 l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;
    i64 b1 = (l / n + 1) * n - 1;
    i64 b2 = (r / n) * n;
    if (b1 == b2) {
      // len of 1
      cout << sum << endl;
    } else if (b1 > b2) {
      i64 c = l / n;
      // same cyclic shift
      i64 ans = get_cyclic_shift_sum(c, l, r);
      cout << ans << endl;
    } else if (b1+1 == b2) {
      // intersect 2 cyclic shift
      i64 c1 = l / n;
      i64 c2 = r / n;
      i64 ans = get_cyclic_shift_sum(c1, l, b1) + get_cyclic_shift_sum(c2, b2, r);
      cout << ans << endl;
    } else {
      i64 c1 = l / n;
      i64 c2 = r / n;
      i64 ans = get_cyclic_shift_sum(c1, l, b1) + get_cyclic_shift_sum(c2, b2, r) + (b2 - b1) / n * sum;
      cout << ans << endl;
    }
  }
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
