#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_increasing(vector<int>& ordering) {
  int size = ordering.size();
  for (int i = 1; i < size; ++i) {
    if (ordering[i-1] > ordering[i]) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[p[i]].push_back(i);
  }

  vector<int> smallest_leaf(n+1, n);
  auto dfs1 = [&](const auto& self, int node) -> void {
    if (a[node]) {
      smallest_leaf[node] = a[node];
      return;
    }

    for (int next_node : adj[node]) {
      self(self, next_node);
      smallest_leaf[node] = min(smallest_leaf[node], smallest_leaf[next_node]);
    }

    vector<pair<int,int>> p;
    for (int next_node : adj[node]) {
      p.push_back({smallest_leaf[next_node], next_node});
    }

    int min_index = min_element(p.begin(), p.end()) - p.begin();
    adj[node].clear();

    int size = p.size();
    for (int i = min_index; i < size; ++i) {
      adj[node].push_back(p[i].second);
    }
    for (int i = 0; i < min_index; ++i) {
      adj[node].push_back(p[i].second);
    }
  };

  dfs1(dfs1, 1);

  vector<int> ordering;
  auto dfs2 = [&](const auto& self, int node) -> void {
    if (a[node]) {
      ordering.push_back(a[node]);
      return;
    }

    for (int next_node : adj[node]) {
      self(self, next_node);
    }
  };

  dfs2(dfs2, 1);

  if (is_increasing(ordering)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
