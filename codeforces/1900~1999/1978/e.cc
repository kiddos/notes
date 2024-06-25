#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;

  // solve full string
  vector<int> c(n), d(n);
  auto perform_ops = [&](int l, int r) {
    for (int i = l; i <= r; ++i) {
      d[i] = b[i] == '1' ? 1 : 0;
      c[i] = a[i] == '1' ? 1 : 0;
    }
    for (int i = l+2; i <= r; ++i) {
      if (a[i-2] == '0' && a[i] == '0') {
        d[i-1] = 1;
      }
    }
    for (int i = l+2; i <= r; ++i) {
      if (d[i-2] && d[i]) {
        c[i-1] = 1;
      }
    }
  };

  perform_ops(0, n-1);

  vector<int> p = c;
  for (int i = 1; i < n; ++i) {
    p[i] += p[i-1];
  }

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;
    int len = r - l + 1;
    if (len <= 8) {
      perform_ops(l, r);
      int ans = 0;
      for (int i = l; i <= r; ++i) {
        ans += c[i];
      }
      cout << ans << endl;
    } else {
      int presum = p[r-4] - p[l+3];
      int left_ends = 0, right_ends = 0;
      perform_ops(l, l + 7);
      for (int i = l; i <= l+3; ++i) {
        left_ends += c[i];
      }
      perform_ops(r - 7, r);
      for (int i = r-3; i <= r; ++i) {
        right_ends += c[i];
      }

      // cout << "middle=" << presum << endl;
      // for (int i = l; i <= r; ++i) {
      //   cout << c[i] << " ";
      // }
      // cout << endl;
      // for (int i = l; i <= r; ++i) {
      //   cout << d[i] << " ";
      // }
      // cout << endl;
      // cout << "left=" << left_ends << ", right=" << right_ends << endl;
      int ans = presum + left_ends + right_ends;
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
