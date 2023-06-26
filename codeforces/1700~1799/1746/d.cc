#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  ll K = 0;
  cin >> n >> K;
  vector<int> parent(n+1, -1);
  for (int i = 2; i <= n; ++i) cin >> parent[i];
  vector<ll> scores(n+1);
  for (int i = 1; i <= n; ++i) cin >> scores[i];

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[parent[i]].push_back(i);
  }

  vector<unordered_map<ll, ll>> memo(n+1);
  function<ll(int,ll)> dfs = [&](int node, ll k) -> ll {
    if (k == 0) {
      return 0LL;
    }
    if (memo[node].count(k)) return memo[node][k];

    if (adj[node].size() == 0) {
      return scores[node] * k;
    }

    int num_children = adj[node].size();
    int k0 = k / num_children;
    int extra = k - k0 * num_children;

    ll ans = scores[node] * k;
    if (k % num_children == 0) {
      for (int child : adj[node]) {
        ans += dfs(child, k0);
      }
    } else {
      vector<ll> diff(num_children);
      for (int child : adj[node]) {
        ll v1 = dfs(child, k0+1);
        ll v2 = dfs(child, k0);
        ans += v2;
        diff.push_back(v1 - v2);
      }
      sort(diff.rbegin(), diff.rend());
      for (int i = 0; i < extra; ++i) {
        ans += diff[i];
      }
    }

    return memo[node][k] = ans;
  };

  ll ans = dfs(1, K);
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
