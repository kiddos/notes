#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  i64 d = 0;
  cin >> n >> k >> d;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> v(k);
  for (int i = 0; i < k; ++i) cin >> v[i];

  i64 ans = 0;
  for (int i = 0; i <= min(d-1, 2LL * n); ++i) {
    i64 current = (d - i - 1) / 2;
    for (int j = 0; j < n; ++j) {
      current += a[j] == (j+1);
    }
    ans = max(ans, current);
    for (int j = 0; j < v[i % k]; ++j) {
      a[j] += 1;
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
