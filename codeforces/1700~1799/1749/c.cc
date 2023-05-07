#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  auto can_win = [&](int k) {
    multiset<int> s(a.begin(), a.end());
    for (int i = 1; i <= k; ++i) {
      auto u = s.upper_bound(k-i+1);
      if (u == s.begin()) {
        return false;
      }
      s.erase(prev(u));
      if (s.empty()) {
        return true;
      }

      int val = *s.begin();
      s.erase(s.begin());
      s.insert(val + k-i+1);
    }
    return true;
  };

  int l = 0, r = n;
  int ans = 0;
  while (l <= r) {
    int m = l + (r-l) / 2;
    if (can_win(m)) {
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
