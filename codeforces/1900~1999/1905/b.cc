#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> degree(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    degree[u]++;
    degree[v]++;
  }

  int b = 0;
  for (int i = 1 ; i <= n; ++i) {
    if (degree[i] > 2) {
      b += degree[i] - 2;
    }
  }
  int ans = (b+1) / 2 + 1;
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
