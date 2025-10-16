#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> p(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }
  vector<vector<int>> adj(n+1);
  vector<int> outdegree(n+1);
  for (int i = 2; i <= n; ++i) {
    adj[p[i]].push_back(i);
    outdegree[p[i]]++;
  }

  vector<int> level;
  queue<int> q;
  q.push(1);
  int d = 0;
  vector<int> depths(n+1);
  while (!q.empty()) {
    level.push_back(q.size());
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();
      depths[node] = d;
      for (int next_node : adj[node]) {
        q.push(next_node);
      }
    }
    d++;
  }

  // for (int l : level) {
  //   cout << l << " ";
  // }
  // cout << endl;

  vector<int> prefix = {0};
  int size = level.size();
  for (int i = 0; i < size; ++i) {
    prefix.push_back(prefix.back() + level[i]);
  }

  constexpr int MAX_N = 200000;
  bitset<MAX_N+1> dp;
  dp.set(0, 1);
  int ans = 0;
  for (int i = 0; i < size; ++i) {
    dp = dp | dp << level[i];
    int l = max(prefix[i+1] - (n-k), 0);
    if ((int)dp._Find_next(l-1) <= k) {
      ans = max(ans, i+1);
    }
  }

  int leaf_depth = *max_element(depths.begin(), depths.end());
  for (int node = 1; node <= n; ++node) {
    if (outdegree[node] == 0) {
      leaf_depth = min(leaf_depth, depths[node]);
    }
  }

  ans = min(ans, leaf_depth+1);
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
