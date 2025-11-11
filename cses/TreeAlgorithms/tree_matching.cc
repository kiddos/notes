#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    edges.emplace_back(a, b);
  }

  vector<vector<int>> adj(n+1);
  for (auto [a, b] : edges) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<vector<int>> memo(n+1, vector<int>(2, -1));
  auto dp = [&](const auto& self, int node, int p, int take) -> int {
    if (memo[node][take] >= 0) {
      return memo[node][take];
    }

    int ans = 0;
    if (take) {
      vector<int> select, no_select;
      for (int next_node : adj[node]) {
        if (next_node == p) {
          continue;
        }
        select.push_back(self(self, next_node, node, 0) + 1);
        no_select.push_back(self(self, next_node, node, 1));
      }
      int total_no_select = accumulate(no_select.begin(), no_select.end(), 0);
      int size = no_select.size();
      for (int i = 0; i < size; ++i) {
        ans = max(ans, total_no_select - no_select[i] + select[i]);
      }
    } else {
      for (int next_node : adj[node]) {
        if (next_node == p) {
          continue;
        }
        ans += self(self, next_node, node, 1);
      }
    }
    return memo[node][take] = ans;
  };

  int ans1 = dp(dp, 1, 1, 0);
  int ans2 = dp(dp, 1, 1, 1);
  int ans = max(ans1, ans2);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
