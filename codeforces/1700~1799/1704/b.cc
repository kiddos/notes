#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  ll x = 0;
  cin >> n >> x;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  auto can_finish = [&](int change) {
    int c = 1;
    ll max_val = numeric_limits<int>::min();
    ll min_val = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
      max_val = max(max_val, a[i]);
      min_val = min(min_val, a[i]);

      if (max_val - min_val > 2 * x) {
        c++;
        max_val = a[i];
        min_val = a[i];
      }
    }
    return c <= change;
  };

  int l = 1, r = n;
  int ans = n-1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (can_finish(mid)) {
      ans = mid-1;
      r = mid-1;
    } else {
      l = mid+1;
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
