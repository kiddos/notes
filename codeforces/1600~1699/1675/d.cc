#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> parents(n+1);
  for (int i = 1; i <= n; ++i) cin >> parents[i];

  int root = 0;
  vector<vector<int>> adj(n+1);
  for (int i = 1; i <= n; ++i) {
    if (parents[i] == i) {
      root = i;
    } else {
      adj[parents[i]].push_back(i);
    }
  }

  int ans = 1;
  vector<vector<int>> paths;
  function<void(int,int,vector<int>&)> dfs = [&](int node, int parent, vector<int>& p) {
    p.push_back(node);

    int child_count = 0;
    for (int next_node : adj[node]) if (node != parent) {
      if (++child_count > 1) {
        ans++;
        vector<int> new_p;
        dfs(next_node, node, new_p);
      } else {
        dfs(next_node, node, p);
      }
    }
    
    if (child_count == 0) {
      paths.push_back(p);
    }

    p.pop_back();
  };

  vector<int> p;
  dfs(root, -1, p);

  cout << ans << endl;
  for (vector<int>& path : paths) {
    cout << path.size() << endl;
    for (int node : path) cout << node << " ";
    cout << endl;
  }
  cout << endl;
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
