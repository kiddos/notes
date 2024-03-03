#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;
constexpr int MAX_N = 300000;

vector<int> f(MAX_N+1, 1);
vector<int> inv_f(MAX_N+1, 1);

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }

    x = x * x;
    x %= MOD;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> degree(n+1);
  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  i64 total = 1;
  function<int(int,int)> dfs = [&](int node, int p) {
    i64 ans = 1;
    for (int next_node : adj[node]) if (next_node != p) {
      ans *= (dfs(next_node, node) + 1);
      ans %= MOD;
    }
    total += ans;
    total %= MOD;
    return ans;
  };

  dfs(1, -1);

  cout << total << endl;
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
