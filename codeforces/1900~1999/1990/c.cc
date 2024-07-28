#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> c(n+1);
  vector<int> b1(n);
  vector<int> d(n+1);
  int mad = 0;
  for (int i = 0; i < n; ++i) {
    if (++c[a[i]] >= 2) {
      mad = max(mad, a[i]);
    }
    b1[i] = mad;
  }
  fill(c.begin(), c.end(), 0);
  vector<int> b2(n);
  mad = 0;
  for (int i = 0; i < n; ++i) {
    if (++c[b1[i]] >= 2) {
      mad = max(mad, b1[i]);
    }
    b2[i] = mad;
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i];
    ans += b1[i];
    ans += (i64) b2[i] * (n-i);
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
