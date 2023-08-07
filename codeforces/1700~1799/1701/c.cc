#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) cin >> a[i];
  vector<int> tasks(n+1);
  for (int i = 0; i < m; ++i) {
    tasks[a[i]]++;
  }

  auto can_complete = [&](ll t) -> bool {
    ll space_left = 0;
    for (int w = 1; w <= n; ++w) {
      if (tasks[w] > t) {
        space_left -= tasks[w] - t;
      } else {
        space_left += (t- tasks[w]) / 2;
      }
    }
    return space_left >= 0;
  };

  ll l = 1, r = 2 * m;
  ll ans = r;
  while (l <= r) {
    ll mid = l + (r-l) / 2;
    if (can_complete(mid)) {
      ans = mid;
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
