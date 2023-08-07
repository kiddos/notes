#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<pair<int,int>> edges;
  vector<int> degree(n+1);
  for (int i = 0; i < m; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;

    degree[x]++;
    degree[y]++;
    edges.push_back({x, y});
  }

  if (m % 2 == 0) {
    cout << "0" << endl;
    return;
  }

  int ans = numeric_limits<int>::max();
  for (int node = 1; node <= n; ++node) if (degree[node] % 2 == 1) {
    ans = min(ans, a[node]);
  }

  for (auto& [x, y] : edges) {
    if (degree[x] % 2 == 0 && degree[y] % 2 == 0) {
      ans = min(ans, a[x] + a[y]);
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
