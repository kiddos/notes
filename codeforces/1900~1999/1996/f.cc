#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  auto can_reduce = [&](int min_a) -> bool {
    i64 total_b = 0;
    for (int i = 0; i < n; ++i) {
      int diff = max(a[i] - min_a, 0);
      total_b += (diff + b[i] - 1) / b[i];
    }
    return total_b <= k;
  };

  int l = 0, r = *max_element(a.begin(), a.end());
  int a_base = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (can_reduce(mid)) {
      r = mid - 1;
      a_base = mid;
    } else {
      l = mid + 1;
    }
  }

  // cout << "abase = " << a_base << endl;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int diff = max(a[i] - a_base, 0);
    i64 bs = (diff + b[i] - 1) / b[i];
    if (bs > 0) {
      int a2 = a[i] - (bs-1) * b[i];
      ans += (i64)(a[i] + a2) * bs / 2;
    }
    a[i] = a[i] - bs * b[i];
    k -= bs;
  }

  sort(a.rbegin(), a.rend());
  for (int i = 0; i < n && a[i] > 0 && k > 0; ++i) {
    ans += a[i];
    k--;
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;

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
