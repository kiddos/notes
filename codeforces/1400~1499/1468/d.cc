#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0,  m = 0, a = 0, b = 0;
  cin >> n >> m >> a >> b;
  vector<int> s(m);
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }

  sort(s.begin(), s.end());
  int at_most = min(abs(a-b) - 1, m);
  int caught_at = (a < b) ? b - 1 : n - b;

  auto all_explode = [&](int count) -> bool {
    for (int i = count-1, t = 1; i >= 0; --i, ++t) {
      int explode_at = s[i] + t;
      if (explode_at > caught_at) {
        return false;
      }
    }
    return true;
  };

  int l = 0, r = at_most;
  int ans = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (all_explode(mid)) {
      l = mid+1;
      ans = mid;
    } else {
      r = mid-1;
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
