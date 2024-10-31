#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  vector<bool> visited(n+1);
  function<int(int)> dfs = [&](int x) -> int {
    if (visited[x]) return 0;
    visited[x] = true;
    return dfs(p[x]) + 1;
  };

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      int len = dfs(i);
      ans += (len - 1) / 2;
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
