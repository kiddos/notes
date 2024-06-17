#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  map<int, int> d;
  for (int i = 0; i < n; ++i) {
    d[a[i]] = i;
  }
  for (auto it = next(d.begin()); it != d.end(); ++it) {
    auto p = prev(it);
    it->second = min(it->second, p->second);
  }

  int ans = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    auto it = d.upper_bound(b[i]-1);
    if (it != d.begin()) {
      --it;
      int move = i + it->second;
      ans = min(ans, move);
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
