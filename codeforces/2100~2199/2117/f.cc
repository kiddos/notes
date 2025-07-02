#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;
i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }

    n >>= 1;
    x = (x * x) % MOD;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }
  vector<vector<int>> adj(n+1);
  vector<int> degree(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }

  int leaf_nodes = 0;
  for (int node = 2; node <= n; ++node) {
    if (degree[node] == 1) {
      leaf_nodes++;
    }
  }

  // total leaf node cannot be more than 2
  // since we can only assign 1 or 2
  if (leaf_nodes > 2) {
    cout << "0" << endl;
    return;
  }

  if (leaf_nodes == 1) {
    cout << power(2, n) << endl;
    return;
  }

  vector<int> total_children(n+1, 1);
  vector<vector<int>> children(n+1);
  auto dfs = [&](const auto& self, int node, int p) -> void {
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      self(self, next_node, node);
      total_children[node] += total_children[next_node];
      children[node].push_back(next_node);
    }
  };

  dfs(dfs, 1, 1);

  int branch_node = 1;
  for (int node = 1; node <= n; ++node) {
    if (children[node].size() == 2) {
      branch_node = node;
      break;
    }
  }

  assert(children[branch_node].size() == 2);

  i64 rest = n - total_children[branch_node] + 1;

  int node1 = children[branch_node][0];
  int node2 = children[branch_node][1];
  i64 count1 = total_children[node1];
  i64 count2 = total_children[node2];
  if (count1 == count2) {
    i64 ans = 2 * power(2, rest);
    ans %= MOD;
    cout << ans << endl;
    return;
  }

  if (count1 > count2) {
    swap(count1, count2);
  }

  // shorter one start assign with 1
  int left = count2 - count1;
  i64 up_to_branch = power(2, left);
  // longer one start assign with 2
  left = count2 - count1 - 1;
  up_to_branch += power(2, left);
  up_to_branch %= MOD;

  i64 ans = up_to_branch * power(2, rest);
  ans %= MOD;
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
