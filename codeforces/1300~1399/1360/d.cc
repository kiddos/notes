#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> f;
  for (int d = 1; d*d <= n; ++d) {
    if (n % d == 0) {
      f.push_back(d);
      f.push_back(n / d);
    }
  }
  sort(f.begin(), f.end());
  f.resize(unique(f.begin(), f.end()) - f.begin());

  int ans = numeric_limits<int>::max();
  for (int fac : f) {
    if (fac <= k) {
      int package = n / fac;
      ans = min(ans, package);
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
