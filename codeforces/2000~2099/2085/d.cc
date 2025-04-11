#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }

  // for each of the group we can only take 1
  // the rest of the group can be uses for the next group
  vector<int> group(n);
  int g = 1;
  for (int i = n-k-1, c = 0; i >= 0; --i) {
    group[i] = g;
    if (++c >= k+1) {
      g++;
      c = 0;
    }
  }

  vector<vector<i64>> group_vals(g+1);
  for (int i = 0; i < n; ++i) {
    group_vals[group[i]].push_back(d[i]);
  }

  i64 ans = 0;
  multiset<i64> pool;
  for (int i = g; i >= 1; --i) {
    if (group_vals[i].empty()) {
      continue;
    }
    sort(group_vals[i].begin(), group_vals[i].end());
    if (!pool.empty() && *pool.rbegin() >= group_vals[i].back()) {
      ans += *pool.rbegin();
      pool.erase(prev(pool.end()));
    } else {
      // take the largest from this group
      // and push the rest to the pool
      ans += group_vals[i].back();
      group_vals[i].pop_back();
    }

    while (!group_vals[i].empty()) {
      pool.insert(group_vals[i].back());
      group_vals[i].pop_back();
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
