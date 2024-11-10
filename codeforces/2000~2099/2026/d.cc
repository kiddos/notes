#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<i64> p = a;
  for (int i = 1; i <= n; ++i) {
    p[i] += p[i-1];
  }
  vector<i64> b1 = p;
  for (int i = 1; i <= n; ++i) {
    b1[i] += b1[i-1];
  }

  vector<i64> b_sum = {0, b1[n]};
  vector<i64> sizes = {0, n};
  for (int i = 2; i <= n; ++i) {
    i64 current_b = b_sum.back() - a[i-1] * (n-i+2);
    b_sum.push_back(current_b);
    sizes.push_back(n-i+1);
  }

  // for (int i = 0; i <= n; ++i) {
  //   cout << b_sum[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i <= n; ++i) {
  //   cout << sizes[i] << " ";
  // }
  // cout << endl;

  vector<i64> b_sum_prefix = b_sum;
  for (int i = 1; i <= n; ++i) {
    b_sum_prefix[i] += b_sum_prefix[i-1];
    sizes[i] += sizes[i-1];
  }

  auto prefix_s = [&](int l, int r) -> i64 {
    return (b1[r] - b1[l-1]) - p[l-1] * (r-l+1);
  };

  auto prefix = [&](i64 x) -> i64 {
    int l = 0, r = n;
    int idx = 0;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (sizes[mid] <= x) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    i64 ans = b_sum_prefix[idx];
    i64 left = x - sizes[idx];
    // cout << "size=" << sizes[idx];
    // cout << " ,left=" << left << ", idx=" << idx << endl;
    // cout << "s(" << idx+1 << "," << idx+left << ")=" << prefix_s(idx+1, idx+left) << endl;
    ans += prefix_s(idx+1, idx+left);
    // cout << "prefix(" <<x << ")=" << ans << endl;
    return ans;
  };

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    i64 l = 0, r = 0;
    cin >> l >> r;
    i64 sum = prefix(r) - prefix(l-1);
    cout << sum << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
