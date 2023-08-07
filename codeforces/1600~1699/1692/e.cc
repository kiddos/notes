#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, s = 0;
  cin >> n >> s;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int ans = numeric_limits<int>::max();
  map<int, int> index = {{0, 0}};
  for (int i = 1, p = 0; i <= n; ++i) {
    p += a[i];
    if (index.count(p - s)) {
      int len = i - index[p-s];
      ans = min(ans, n - len);
    }

    if (!index.count(p)) {
      index[p] = i;
    }
  }

  if (ans == numeric_limits<int>::max()) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
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
