#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> x(m+1);
  for (int i = 0; i <= m; ++i) {
    cin >> x[i];
  }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    int diff = x[i] ^ x[m];
    int c = 0;
    for (int b = 0; b < n; ++b) {
      if (diff & (1<<b)) {
        c++;
      }
    }
    if (c <= k) {
      ans++;
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
