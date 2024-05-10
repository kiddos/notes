#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<bool> found(n+1);
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    found[b] = true;
  }

  int root = 0;
  for (int node = 1; node <= n; ++node) {
    if (!found[node]) {
      root = node;
      break;
    }
  }

  vector<pair<int,int>> ans;
  for (int node = 1; node <= n; ++node) if (node != root) {
    ans.emplace_back(root, node);
  }

  for (auto& [u, v] : ans) {
    cout << u << " " << v << endl;
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
