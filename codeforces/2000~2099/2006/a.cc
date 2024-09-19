#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }
  string s;
  cin >> s;
  s = " " + s;

  vector<vector<int>> adj(n+1);
  for (auto& [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  // just count start and end
  // if different, then score + 1
  vector<pair<char,char>> pairs;
  vector<bool> is_leaf(n+1, false);
  function<void(int,int)> dfs = [&](int node, int p) {
    if (adj[node].size() == 1 && node != 1) {
      pairs.emplace_back(s[1], s[node]);
      is_leaf[node] = true;
    }

    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }
      dfs(next_node, node);
    }
  };

  dfs(1, 0);

  int ans = 0;
  if (s[1] == '?') {
    int one = 0, zero = 0, unknown = 0;
    for (auto& [c1, c2] : pairs) {
      // cout << c1 << ", " << c2 << endl;
      if (c2 == '1') {
        one++;
      } else if (c2 == '0') {
        zero++;
      } else {
        unknown++;
      }
    }
    if (one > zero) {
      ans += one + unknown / 2;
    } else if (zero > one) {
      ans += zero + unknown / 2;
    } else {
      ans += zero;
      int middle = 0;
      for (int node = 2; node <= n; ++node) {
        if (!is_leaf[node] && s[node] == '?') {
          middle++;
        }
      }
      if (middle % 2 == 1) {
        ans += (unknown + 1) / 2;
      } else {
        ans += unknown / 2;
      }
    }
  } else {
    int unknown = 0;
    for (auto& [c1, c2] : pairs) {
      if (c2 == '?') {
        unknown++;
      } else {
        if (c1 != c2) {
          ans++;
        }
      }
    }
    ans += (unknown+1) / 2;
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
