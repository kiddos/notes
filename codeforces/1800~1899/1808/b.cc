#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> c(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> c[i][j];
  }

  ll ans = 0;
  for (int j = 0; j < m; ++j) {
    vector<ll> col;
    for (int i = 0; i < n; ++i) col.push_back(c[i][j]);
    sort(col.begin(), col.end());

    ll sum = accumulate(col.begin(), col.end(), 0LL);
    for (int i = 0; i < n; ++i) {
      sum -= col[i];
      ans += sum - (n-i-1) * col[i];
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
