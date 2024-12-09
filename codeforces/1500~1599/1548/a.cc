#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<set<int>> adj(n+1);
  for (auto& [u, v] : edges) {
    adj[u].insert(v);
    adj[v].insert(u);
  }

  set<int> live;
  auto will_survive = [&](int noble) -> bool {
    if (adj[noble].empty()) {
      return true;
    }
    int largest = *adj[noble].rbegin();
    return largest < noble;
  };

  for (int noble = 1; noble <= n; ++noble) {
    if (will_survive(noble)) {
      live.insert(noble);
    }
  }

  auto check = [&](int noble) {
    if (will_survive(noble)) {
      live.insert(noble);
    } else{
      live.erase(noble);
    }
  };

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int u = 0, v = 0;
      cin >> u >> v;
      adj[u].insert(v);
      adj[v].insert(u);

      check(u);
      check(v);
    } else if (type == 2) {
      int u = 0, v = 0;
      cin >> u >> v;
      adj[u].erase(v);
      adj[v].erase(u);

      check(u);
      check(v);
    } else if (type == 3) {
      int ans = live.size();
      cout << ans << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
