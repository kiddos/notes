#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> parent(n+1);
  for (int i = 2; i <= n; ++i) {
    cin >> parent[i];
  }

  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[parent[i]].push_back(i);
  }

  vector<int> depths(n+1);
  vector<int> child_depths;
  function<void(int)> dfs = [&](int node) {
    if (adj[node].size() == 0) {
      child_depths.push_back(depths[node]);
      return;
    }

    for (int child : adj[node]) {
      depths[child] = depths[node] + 1;
      dfs(child);
    }
  };

  dfs(1);

  auto count_cut = [&](int len) -> int {
    vector<pair<int,int>> nodes;
    for (int node = 1; node <= n; ++node) {
      nodes.push_back({depths[node], node});
    }
    sort(nodes.rbegin(), nodes.rend());

    int ans = 0;
    vector<bool> visited(n+1);
    for (auto [d, node] : nodes) {
      if (d > len) {
        int current = node;
        if (!visited[current]) {
          visited[current] = true;
          bool cut = true;
          for (int k = 1; k < len; ++k) {
            current = parent[current];
            if (visited[current]) {
              cut = false;
              break;
            }
            visited[current] = true;
          }

          if (cut) {
            ans++;
          }
        }
      }
    }
    return ans;
  };

  int l = 1, r = *max_element(child_depths.begin(), child_depths.end());
  int ans = 1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (count_cut(mid) <= k) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
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
