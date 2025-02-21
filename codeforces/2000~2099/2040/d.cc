#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 400000;
vector<int> w;

void precompute() {
  vector<int> is_prime(MAX_N+1, true);
  is_prime[1] = false;
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      for (int j = i+i; j <= MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (int i = 1; i <= MAX_N; ++i) {
    if (!is_prime[i]) {
      w.push_back(i);
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> edges;
  for (int i = 1; i < n; ++i) {
    int u = 0, v = 0;
    cin >> u >> v;
    edges.emplace_back(u, v);
  }

  vector<vector<int>> adj(n+1);
  for (auto [u, v] : edges) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> assigned(n * 2 + 1);
  vector<int> a(n+1);
  function<void(int,int)> dfs = [&](int node, int p) {
    int k = 0;
    for (int next_node : adj[node]) {
      if (next_node == p) {
        continue;
      }

      while (k < (int)w.size() && a[node] + w[k] <= 2 * n && assigned[a[node] + w[k]]) {
        k++;
      }
      a[next_node] = a[node] + w[k++];
      assigned[a[next_node]] = true;
      dfs(next_node, node);
    }
  };

  int start = 0;
  for (int node = 1; node <= n; ++node) {
    if (adj[node].size() == 1) {
      start = node;
      break;
    }
  }

  a[start] = 1;
  dfs(start, 0);

  for (int node = 1; node <= n; ++node) {
    cout << a[node] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
