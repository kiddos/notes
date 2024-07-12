#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> p(n+1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[p[i]].push_back(i);
  }

  constexpr i64 INF = numeric_limits<i64>::max();
  vector<i64> b(n+1);
  function<void(int)> dfs1 = [&](int node) {
    b[node] = -a[node];
    for (int next_node : adj[node]) {
      b[node] += a[next_node];

      dfs1(next_node);
    }

    if (adj[node].empty()) {
      b[node] = INF;
    }
  };
  dfs1(1);

  i64 ans = 0;
  auto bfs = [&](int node) {
    queue<int> q;
    for (int next_node : adj[node]) {
      q.push(next_node);
    }

    i64 dist = 1;
    while (!q.empty() && b[node] < 0) {
      for (int size = q.size(); size > 0; --size) {
        int x = q.front();
        q.pop();
        if (b[x] > 0) {
          i64 need = -b[node];
          i64 can_give = b[x];
          i64 change = min(need, can_give);
          b[node] += change;
          b[x] -= change;

          ans += dist * change;
        }

        for (int next_node : adj[x]) {
          q.push(next_node);
        }
      }
      dist++;
    }
  };

  function<void(int)> dfs2 = [&](int node) {
    for (int next_node : adj[node]) {
      dfs2(next_node);
    }
    if (b[node] < 0) {
      bfs(node);
    }
  };

  dfs2(1);

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
