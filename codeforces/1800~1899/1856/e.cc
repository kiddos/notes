#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 1e6;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> parent(n+1, -1);
  for (int i = 2; i <= n; ++i) cin >> parent[i];

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[parent[i]].push_back(i);
  }

  int ans = 0;
  function<int(int,int)> dfs = [&](int node, int p) -> int {
    vector<int> counts;
    for (int next_node : adj[node]) if (next_node != p) {
      counts.push_back(dfs(next_node, node));
    }
    // cout << "children size: ";
    // for (int c : counts) cout << c << " ";
    // cout << endl;
    int total = accumulate(counts.begin(), counts.end(), 0);
    vector<bool> dp(total+1);
    dp[0] = true;
    int max_mul = 0;

    for (int i = 0; i < counts.size(); ++i) {
      vector<bool> next_dp = dp;
      for (int a = 0; a+counts[i] <= total; ++a) {
        if (dp[a]) {
          next_dp[a+counts[i]] = true;
          int x = a + counts[i];
          int y = total - x;
          max_mul = max(max_mul, x * y);
        }
      }
      dp = move(next_dp);
    }

    // cout << "max mul=" << max_mul << endl;
    ans += max_mul;
    return total + 1;
  };

  dfs(1, -1);

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
