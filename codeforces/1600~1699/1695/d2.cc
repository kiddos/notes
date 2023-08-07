#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  
  vector<int> degree(n+1);
  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int x = 0, y= 0;
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
    degree[x]++;
    degree[y]++;
  }

  if (n == 1) {
    cout << "0" << endl;
    return;
  }

  // if the tree is just a simple path
  // then we can just return 1 (query from the end point)
  // so find a node with degree >= 3
  // if the node does not exist
  // we know this tree is just a simple path

  int root = -1;
  for (int node = 1; node <= n; ++node) if (degree[node] > 2) {
    root = node;
    break;
  }

  if (root == -1) {
    cout << "1" << endl;
    return;
  }

  function<int(int,int)> dfs = [&](int node, int parent) -> int {
    int ans = 0, extra = 0;
    for (int child : adj[node]) if (child != parent) {
      int result = dfs(child, node);
      ans += result;
      if (result == 0) {
        extra++;
      }
    }
    return ans + max(0, extra-1);
  };

  int ans = dfs(root, -1);
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
