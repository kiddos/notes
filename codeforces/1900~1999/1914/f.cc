#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 2; i <= n; ++i) cin >> p[i];

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[p[i]].push_back(i);
  }

  vector<int> size(n+1);
  function<void(int)> dfs1 = [&](int node) {
    size[node] = 1;
    for (int child : adj[node]) {
      dfs1(child);
      size[node] += size[child];
    }
  };
  dfs1(1);

  function<int(int,int)> dfs2 = [&](int node, int used) {
    int total = 0;
    int max_unmatch = 0;
    int max_child = 0;
    for (int child : adj[node]) {
      if (size[child] > max_unmatch) {
        max_unmatch = size[child];
        max_child = child;
      }
      total += size[child];
    }

    if (total == 0) {
      return 0;
    }
    int rest = total - max_unmatch;
    if (max_unmatch - used <= rest) {
      return (total - used) / 2;
    }
    return rest + dfs2(max_child, max(used + rest - 1, 0));
  };
  
  int ans = dfs2(1, 0);
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
