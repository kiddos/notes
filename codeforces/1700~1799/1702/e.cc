#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  vector<pair<int,int>> pairs;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;

    pairs.emplace_back(a, b);
  }

  vector<int> occur(n+1);
  vector<vector<int>> adj(n+1);
  for (int i = 0; i < n; ++i) {
    auto [a, b] = pairs[i];

    adj[a].push_back(b);
    adj[b].push_back(a);
    occur[a]++;
    occur[b]++;
  }

  for (int i = 1; i <= n; ++i) if (occur[i] != 2) {
    cout << "NO" << endl;
    return;
  }

  for (int x = 1; x <= n; ++x) {
    vector<int>& a = adj[x];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
  }

  vector<bool> visited(n+1);
  function<int(int)> dfs = [&](int x) {
    // cout << "visiteding " << x << ", visited: " << visited[x] << " cycle len=" << len << endl;
    for (int y : adj[x]) if (!visited[y]) {
      visited[y] = true;
      return dfs(y) + 1;
    }
    return 0;
  };

  for (int x = 1; x <= n; ++x) {
    if (!visited[x]) {
      int len = dfs(x);
      // cout << "x=" << x << " cycle len=" << len << endl;
      if (len % 2 != 0) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout << "YES" << endl;
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
