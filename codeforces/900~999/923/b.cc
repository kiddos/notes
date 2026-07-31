#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<i64> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  vector<i64> pt = {0};
  for (int i = 0; i < n; ++i) {
    pt.push_back(pt.back() + t[i]);
  }

  auto compute_melt = [&](int l, int r) -> i64 {
    if (l > r) {
      return 0;
    }
    return pt[r+1] - pt[l];
  };

  vector<i64> line(n+1);
  vector<i64> extra(n+1);
  for (int i = 0; i < n; ++i) {
    int l = i, r = n-1;
    int idx = n;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 total_melt = compute_melt(i, mid);
      if (total_melt > v[i]) {
        idx = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }

    line[i] += 1;
    line[idx] -= 1;
    i64 melt_before = compute_melt(i, idx-1);
    extra[idx] += v[i] - melt_before;
  }

  // for (int i = 0; i <= n; ++i) {
  //   cout << line[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i <= n; ++i) {
  //   cout << extra[i] << " ";
  // }
  // cout << endl;

  vector<i64> ans(n);
  i64 full_melt = 0;
  for (int i = 0; i < n; ++i) {
    full_melt += line[i];
    ans[i] = full_melt * t[i] + extra[i];
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
