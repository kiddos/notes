#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> f(m);
  for (int i = 0; i < m; ++i) {
    cin >> f[i];
  }
  sort(f.begin(), f.end());
  int ans = numeric_limits<int>::max();
  for (int i = n-1; i < m; ++i) {
    int diff = f[i] - f[i-n+1];
    ans = min(ans, diff);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
