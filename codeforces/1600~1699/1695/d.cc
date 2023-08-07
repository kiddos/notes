#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// if the tree looks like this
// 
//    1
//  / | \
// 2  3  4
//
// so we have to query 1, 2, 3, to know where x is
//
// if the tree looks like this
//
//      1
//    / | \
//   2  5  6
//  / \
// 3   4
//
// if we root at 1, the answer would be ans[2] + 2 (eg. query 1, 5)

void solve() {
  int n = 0;
  cin >> n;

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  if (n == 1) {
    cout << "0" << endl;
    return;
  }

  function<int(int,int)> dfs = [&](int node, int p) -> int {
    int ans = 0;
    int extra = 0;
    for (int child : adj[node]) if (child != p) {
      int result = dfs(child, node);
      ans += result;
      if (result == 0) {
        extra++;
      }
    }
    return ans + max(0, extra-1);
  };

  int ans = n;
  for (int root = 1; root <= n; ++root) {
    ans = min(ans, dfs(root, -1) + 1);
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
