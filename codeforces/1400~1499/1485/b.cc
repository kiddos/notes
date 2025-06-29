#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0, k = 0;
  cin >> n >> q >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> p(n);
  for (int i = 1; i < n-1; ++i) {
    i64 low = a[i-1] + 1;
    i64 high = a[i+1] - 1;
    p[i] = high - low;
    p[i] += p[i-1];
  }

  auto query = [&](int l, int r) -> i64 {
    if (l > r) {
      return 0;
    }
    return p[r] - p[l-1];
  };

  vector<i64> ans(q);
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;
    if (l == r) {
      ans[i] = k - 1;
    } else {
      i64 middle = query(l+1, r-1);
      i64 start = a[l+1] - 1 - 1;
      i64 end = k - a[r-1] - 1;
      ans[i] = middle + start + end;
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
