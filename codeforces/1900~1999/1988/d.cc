#include <bits/stdc++.h>

using namespace std;

using i64 = long long int;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  constexpr int ROUNDS = 20;
  vector<vector<int>> other_rounds(ROUNDS+1);
  for (int r = 1; r <= ROUNDS; ++r) {
    for (int r2 = 1; r2 <= ROUNDS; ++r2) {
      if (r2 != r) {
        other_rounds[r].push_back(r2);
      }
    }
  }

  vector<vector<i64>> memo(n+1, vector<i64>(ROUNDS+1, -1));
  function<i64(int,int,int)> dfs = [&](int node, int p, int kill_at_round) -> i64 {
    if (memo[node][kill_at_round] >= 0) {
      return memo[node][kill_at_round];
    }

    i64 ans = (i64)kill_at_round * a[node];
    for (int next_node : adj[node]) if (next_node != p) {
      i64 best = numeric_limits<i64>::max();
      for (int other_round : other_rounds[kill_at_round]) {
        best = min(best, dfs(next_node, node, other_round));
      }
      ans += best;
    }
    return memo[node][kill_at_round] = ans;
  };

  i64 ans = numeric_limits<i64>::max();
  for (int k = 1; k <= ROUNDS; ++k) {
    ans = min(ans, dfs(1, -1, k));
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
