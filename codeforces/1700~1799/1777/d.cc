#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll x, ll n, ll mod) {
  ll ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }

    x = x * x;
    x %= mod;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> adj(n+1);
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  constexpr int MOD = 1e9 + 7;
  ll p2 = power(2, n-1, MOD);
  ll ans = 0;
  function<ll(int,int)> dfs = [&](int node, int parent) -> ll{
    ll d = 0;
    for (int next_node : adj[node]) if (next_node != parent) {
      d = max(d, dfs(next_node, node));
    }
    ans += (p2 * (d+1));
    ans %= MOD;
    return d+1;
  };

  dfs(1, -1);

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
