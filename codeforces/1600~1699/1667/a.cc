#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<i64> b(n);
  auto start = [&](int idx) {
    i64 ans = 0;
    fill(b.begin(), b.end(), 0);

    for (int i = idx+1; i < n; ++i) {
      i64 min_bi = b[i-1]+1;
      i64 ops = (min_bi + a[i] - 1) / a[i];
      ans += ops;
      b[i] = ops * a[i];
    }
    for (int i = idx-1; i >= 0; --i) {
      i64 max_bi = b[i+1]-1;
      i64 ops = (abs(max_bi) + a[i] - 1) / a[i];
      ans += ops;
      b[i] = -ops * a[i];
    }
    return ans;
  };

  i64 ans = start(0);
  for (int i = 1; i < n; ++i) {
    ans = min(ans, start(i));
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
