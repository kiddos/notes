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
  vector<int> degree(n+1);
  vector<vector<int>> adj(n+1);
  for (int i = 2; i <= n; ++i) {
    degree[p[i]]++;
    adj[p[i]].push_back(i);
  }

  // max_vals store the maximum value for each subset
  vector<multiset<i64>> max_vals(n+1);
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (degree[i] == 0) {
      q.push(i);
    }
  }

  auto merge = [&](int p, int node) {
    if (max_vals[p].size() < max_vals[node].size()) {
      swap(max_vals[p], max_vals[node]);
    }
    for (i64 val : max_vals[node]) {
      max_vals[p].insert(val);
    }
  };

  vector<i64> can_add;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      int node = q.front();
      q.pop();

      if (max_vals[node].empty()) {
        max_vals[node].insert(a[node]);
      } else {
        // try to remove the smallest
        multiset<i64>& s = max_vals[node];
        i64 min_val = *s.begin();
        s.erase(s.begin());
        s.insert(max(min_val, a[node]));
        can_add.push_back(min(min_val, a[node]));
      }

      int parent = p[node];
      if (parent > 0) {
        merge(parent, node);
        if (--degree[parent] == 0) {
          q.push(parent);
        }
      }
    }
  }

  multiset<i64>& root = max_vals[1];
  int min_k = root.size();

  sort(can_add.begin(), can_add.end());
  vector<i64> ans(n+1, -1);
  ans[min_k] = 0;
  for (i64 val : root) {
    ans[min_k] += val;
  }

  for (int k = min_k+1; k <= n; ++k) {
    ans[k] = ans[k-1] + can_add.back();
    can_add.pop_back();
  }

  for (int k = 1; k <= n; ++k) {
    cout << ans[k] << " ";
  }
  cout << endl;
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
