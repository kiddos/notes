#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) p.push_back(p.back() + a[i]);

  auto find = [&](int start, i64 u) -> int {
    int l = 1, r = n-start;
    int len = 1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 sum = p[start+mid] - p[start];
      if (sum <= u) {
        len = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return len;
  };

  auto increase = [&](int len, int l, i64 u) -> i64 {
    i64 range = p[l+len] - p[l];
    return (u + u + 1 - range) * range / 2;
  };

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l = 0;
    i64 u = 0;
    cin >> l >> u;

    l--;

    int len = find(l, u);
    if (l+len == n) {
      cout << l+len << " ";
    } else {
      i64 sum1 = increase(len, l, u);
      i64 sum2 = increase(len+1, l, u);
      if (sum1 >= sum2) {
        cout << l+len << " ";
      } else {
        cout << l+len+1 << " ";
      }
    }
  }
  cout << endl;
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
