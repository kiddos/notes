#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

constexpr int MAX_VAL = 2 * 1e5;
unordered_map<int, int> prime_factors[MAX_VAL + 1];
 
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

ll solve(int n, vector<vector<int>>& edges) {
  const int MOD = 998244353;
 
  vector<vector<pair<int,pair<ll,ll>>>> adj(n+1);
  for (vector<int>& e : edges) {
    int ing1 = e[0], ing2 = e[1], x = e[2], y = e[3];
    int g = gcd(x, y);
    int r1 = x / g, r2 = y / g;
    adj[ing1].push_back({ing2, {r1, r2}});
    adj[ing2].push_back({ing1, {r2, r1}});
  }
 
  unordered_map<int, int> current;
  unordered_map<int, int> div;
  function<void(int,int)> dfs1 = [&](int ing, int p) {
    for (auto& [next_ing, ratio] : adj[ing]) if (next_ing != p) {
      auto [x, y] = ratio;
      for (auto& [prime, count] : prime_factors[y]) {
        current[prime] -= count;
      }
      for (auto& [prime, count] : prime_factors[x]) {
        current[prime] += count;
        div[prime] = max(div[prime], current[prime]);
      }

      dfs1(next_ing, ing);

      for (auto& [prime, count] : prime_factors[y]) {
        current[prime] += count;
      }
      for (auto& [prime, count] : prime_factors[x]) {
        current[prime] -= count;
      }
    }
  };
  dfs1(1, -1);

  ll ans = 1;
  function<void(int,int,ll)> dfs2 = [&](int ing, int p, ll amount) {
    for (auto& [next_ing, ratio] : adj[ing]) if (next_ing != p) {
      auto [x, y] = ratio;
      // y * ing1 = x * ing2
      // => ing2 = ing1 * y / x
      ll next_amount = amount * y;
      next_amount %= MOD;
      next_amount = mod_div(next_amount, x, MOD);

      ans += next_amount;
      ans %= MOD;

      dfs2(next_ing, ing, next_amount);
    }
  };

  dfs2(1, -1, 1);

  for (auto& [prime, count] : div) {
    ll d = power(prime, count, MOD);
    // cout << "div: " << d << endl;
    ans *= d;
    ans %= MOD;
  }

  return ans;
}

void precompute() {
  for (int num = 2; num <= MAX_VAL; ++num) {
    int x = num;
    for (int d = 2; d*d <= x; ++d) {
      while (x % d == 0) {
        prime_factors[num][d]++;
        x /= d;
      }
    }
    if (x > 1) prime_factors[num][x]++;
  }
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();
 
  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n-1; ++i) {
      int a1 = 0, a2 = 0, x = 0, y = 0;
      cin >> a1 >> a2 >> x >> y;
      edges.push_back({a1, a2, x, y});
    }
    ll ans = solve(n, edges);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
