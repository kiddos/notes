#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int NUM_COLORS = 6;
constexpr int MOD = 1e9 + 7;

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }

    x = (x * x) % MOD;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int k = 0;
  cin >> k;
  int n = 0;
  cin >> n;

  vector<i64> v(n);
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i] >> s[i];
  }

  map<i64, vector<i64>> adj;
  for (int i = 0; i < n; ++i) {
    i64 node = v[i];
    while (node > 1) {
      i64 prev_node = node / 2;
      adj[prev_node].push_back(node);
      node = prev_node;
    }
  }
  for (auto& [node, children] : adj) {
    sort(children.begin(), children.end());
    children.resize(unique(children.begin(), children.end()) - children.begin());
  }

  const unordered_map<string, int> mapping = {
    {"white", 0},
    {"yellow", 1},
    {"green", 2},
    {"blue", 3},
    {"red", 4},
    {"orange", 5},
  };
  map<i64, int> must_be;
  for (int i = 0; i < n; ++i) {
    must_be[v[i]] = mapping.at(s[i]);
  }

  const vector<vector<int>> colors = {
    {2, 3, 4, 5},
    {2, 3, 4, 5},
    {0, 1, 4, 5},
    {0, 1, 4, 5},
    {0, 1, 2, 3},
    {0, 1, 2, 3},
  };

  map<i64, map<int,i64>> memo;
  function<i64(i64, int)> dp = [&](i64 node, int color) -> i64 {
    if (must_be.count(node) && must_be[node] != color) {
      return 0;
    }

    if (memo.count(node) && memo[node].count(color)) {
      return memo[node][color];
    }

    i64 ans = 0;
    vector<i64>& children = adj[node];
    if (children.size() == 0) {
      ans = 1;
    } else if (children.size() == 1) {
      for (int c : colors[color]) {
        ans += dp(children[0], c);
        ans %= MOD;
      }
    } else if (children.size() == 2) {
      for (int c1 : colors[color]) {
        for (int c2 : colors[color]) {
          ans += (dp(children[0], c1) * dp(children[1], c2)) % MOD;
          ans %= MOD;
        }
      }
    }
    return memo[node][color] = ans;
  };

  i64 ans = 0;
  for (int c = 0; c < NUM_COLORS; ++c) {
    ans += dp(1, c);
    ans %= MOD;
  }
  i64 anything = (1LL << k) - 1 - (int)adj.size();
  ans *= power(4, anything);
  ans %= MOD;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
