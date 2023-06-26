#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Edge {
  int i, j, x;
};

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<Edge> edges;
  vector<vector<pair<int,ll>>> adj(n+1);
  vector<int> ans(n+1);
  for (int k = 0; k < q; ++k) {
    int i = 0, j = 0, x = 0;
    cin >> i >> j >> x;
    ans[i] |= x;
    ans[j] |= x;
    edges.push_back(Edge{i, j, x});
    adj[i].push_back({j, x});
    adj[j].push_back({i, x});
  }

  auto can_zero = [&](int i, int b) -> bool {
    for (auto& [j, x] : adj[i]) {
      if (j == i && (x & (1<<b))) return false;

      if ((ans[j] & (1<<b)) != (x & 1<<b)) {
        return false;
      }
    }
    return true;
  };

  for (int b = 30; b >= 0; --b) {
    // try to satify the condition first
    for (auto& [i, j, x] : edges) if (!(x & (1<<b))) {
      if (ans[i] & (1<<b)) {
        ans[i] ^= (1<<b);
      }
      if (ans[j] & (1<<b)) {
        ans[j] ^= (1<<b);
      }
    }

    // and try to make the array as small as possible
    for (int i = 1; i <= n; ++i) if (ans[i] & (1<<b)) {
      if (can_zero(i, b)) {
        ans[i] ^= (1<<b);
      }
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
