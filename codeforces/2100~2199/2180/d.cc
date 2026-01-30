#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  constexpr i64 inf = 1e18;
  vector<i64> max_size(n, inf);
  for (int i = 0; i < n; ++i) {
    if (i+1 < n) {
      i64 gap = x[i+1] - x[i];
      max_size[i] = min(max_size[i], gap);
    }
    if (i > 0) {
      i64 gap = x[i] - x[i-1];
      max_size[i] = min(max_size[i], gap);
    }
  }

  int ans = n-1;
  i64 l = 0, r = max_size[0];
  for (int i = 1; i < n; ++i) {
    i64 gap = x[i] - x[i-1];
    i64 l2 = gap - r;
    i64 r2 = gap - l;
    l = max(l2, 0LL);
    r = min(r2, max_size[i]);
    if (l >= r) {
      ans--;
      l = 0;
      r = max_size[i];
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
