#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<i64> g(m);
  for (int j = 0 ; j < m; ++j) {
    cin >> g[j];
  }

  sort(b.begin(), b.end());
  sort(g.begin(), g.end());

  i64 max_b = b.back();
  i64 min_g = g[0];
  if (max_b > min_g) {
    cout << "-1" << endl;
    return;
  }

  i64 ans = 0;
  if (max_b == min_g) {
    // largest
    for (int j = 0; j < m; ++j) {
      ans += g[j];
    }
    // rest
    for (int i = 0; i < n-1; ++i) {
      ans += b[i] * m;
    }
  } else {
    // largest
    for (int j = 1; j < m; ++j) {
      ans += g[j];
    }
    ans += b.back();
    // second largest
    ans += g[0];
    ans += b[n-2] * (m-1);
    // rest
    for (int i = 0; i < n-2; ++i) {
      ans += b[i] * m;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
