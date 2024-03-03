#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  auto possible = [&](int k) -> bool {
    vector<i64> h2 = h;
    for (int i = n-1; i >= 2; --i) {
      if (h2[i] > k) {
        i64 can_remove = min(h2[i] - k, h[i]);
        h2[i-2] += can_remove / 3 * 2;
        h2[i-1] += can_remove / 3;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (h2[i] < k) {
        return false;
      }
    }
    return true;
  };

  int l = *min_element(h.begin(), h.end());
  int r = *max_element(h.begin(), h.end());
  int ans = l;
  while (l <= r) {
    int m = l + (r-l) / 2;
    if (possible(m)) {
      ans = m;
      l = m+1;
    } else {
      r = m-1;
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
