#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<vector<int>> adj(n+1);
  for (int i = 0; i < k; ++i) {
    vector<int> rank(n);
    for (int j = 0; j < n; ++j) cin >> rank[j];
    for (int j = 1; j+1 < n; ++j) {
      adj[rank[j]].push_back(rank[j+1]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    vector<int>& l = adj[i];
    sort(l.begin(), l.end());
    l.erase(unique(l.begin(), l.end()), l.end());
  }

  vector<int> state(n+1);
  function<bool(int)> dfs = [&](int i) -> bool {
    if (state[i]) {
      return state[i] == 1;
    }

    state[i] = 1;
    for (int j : adj[i]) {
      if (dfs(j)) return true;
    }
    state[i] = 2;
    return false;
  };

  for (int i = 1; i <= n; ++i) {
    if (!state[i]) {
      if (dfs(i)) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
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
