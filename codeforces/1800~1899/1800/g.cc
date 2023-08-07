#include <bits/stdc++.h>

using namespace std;


void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> adj(n+1);
  for (int i= 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<vector<int>> memo(n+1);
  function<vector<int>&(int,int)> dfs = [&](int node, int parent) -> vector<int>& {
    if (memo[node].size() > 0) {
      return memo[node];
    }

    vector<int> ans;
    for (int next_node : adj[node]) if (next_node != parent) {
      vector<int> result = dfs(next_node, node);
      for (int len : result) {
        ans.push_back(len+1);
      }
    }
    if (ans.empty()) {
      return memo[node] = {1};
    }
    sort(ans.begin(), ans.end());
    return memo[node] = ans;
  };

  function<bool(int,int)> is_symmetric = [&](int node, int parent) -> bool {
    map<vector<int>, int> children;
    for (int child : adj[node]) if (child != parent) {
      vector<int>& path_lens = dfs(child, node);

      if (children.count(path_lens)) {
        children.erase(path_lens);
      } else {
        children[path_lens] = child;
      }
    }
    if (children.size() <= 1) {
      if (children.size() == 0) return true;
      return is_symmetric(children.begin()->second, node);
    } else {
      return false;
    }
  };

  bool ans = is_symmetric(1, -1);
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
