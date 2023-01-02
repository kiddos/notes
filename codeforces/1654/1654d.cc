#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct Edge {
  int a1, a2;
  ll x, y;
};

ll extended_euclid(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  ll x1 = 0, y1 = 0;
  ll g = extended_euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}

ll mod_div(ll a, ll b, ll m) {
  ll x = 0, y = 0;
  ll g = extended_euclid(b, m, x, y);
  if (g != 1) {
    return -1;
  } else {
    ll inv_b = (x % m + m) % m;
    return (a * inv_b) % m;
  }
}

struct Fraction {
  ll top, bot;
};
 
ll solve(int n, vector<Edge>& edges) {
  const int MOD = 998244353;
 
  vector<vector<pair<int,Fraction>>> adj(n);
  for (int i = 0; i < edges.size(); ++i) {
    auto& [a1, a2, x, y] = edges[i];
    adj[a1].push_back({a2, Fraction{y, x}});
    adj[a2].push_back({a1, Fraction{x, y}});
  }
 
  ll ans = 0;
  vector<bool> visited(n);
  function<void(int,ll)> dfs = [&](int node, ll value) {
    if (visited[node]) return;
    visited[node] = true;
    ans += value;
    ans %= MOD;
    cout << "value: " << value << endl;
    for (auto& [next_node, frac] : adj[node]) {
      value = (value * frac.top) % MOD;
      ll next_val = mod_div(value, frac.bot, MOD);
      dfs(next_node, next_val);
    }
  };
 
  dfs(0, 1);
  return ans;
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<Edge> edges;
    for (int i = 0; i < n-1; ++i) {
      int a1 = 0, a2 = 0, x = 0, y = 0;
      cin >> a1 >> a2 >> x >> y;
      ll g = gcd(x, y);
      edges.push_back(Edge{a1-1, a2-1, x / g, y / g});
    }
    ll ans = solve(n, edges);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
