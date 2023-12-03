#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  vector<pair<i64, int>> programmers;
  for (int i = 0; i < n; ++i) {
    programmers.emplace_back(a[i], i+1);
  }
  sort(programmers.rbegin(), programmers.rend());

  constexpr int INF = 1e9;
  vector<vector<int>> require(m, vector<int>(n));
  for (int p = 0; p < m; ++p) {
    for (int l = 0, r = 0; l < n; ++l) {
      r = max(r, l);
      while (r < n && (b[p] + r - l) / (r-l+1) > programmers[r].first) {
        r++;
      }
      int len = r-l+1;
      if (r < n && b[p] / len <= programmers[r].first) {
        require[p][l] = (r-l) + 1;
      } else {
        require[p][l] = INF;
      }
      // cout << require[p][l] <<  " ";
    }
    // cout << endl;
  }

  constexpr int MAX_M = 20;
  int size = 1 << m;
  vector<int> dp(size, INF);
  vector<int> parent(size);
  dp[0] = 0;
  for (int mask = 0; mask < size; ++mask) {
    for (int p = 0; p < m; ++p) if (!(mask & (1<<p))) {
      if (dp[mask] >= n) continue;
      int count = require[p][dp[mask]];
      if (count == INF) continue;

      int mask2 = mask | (1<<p);
      int result = dp[mask] + count;
      if (result < dp[mask2]) {
        parent[mask2] = mask;
        dp[mask2] = result;
      }
    }
    // cout << bitset<MAX_M>(mask) << " -> " << bitset<MAX_M>(parent[mask]) << endl;
  }

  if (dp[size-1] == INF) {
    cout << "NO" << endl;
    return;
  }

  auto find_bit = [&](int mask) {
    for (int i = 0; i <= MAX_M; ++i) {
      if (mask & (1<<i)) {
        return i;
      }
    }
    return -1;
  };

  vector<vector<int>> ans(m);
  int mask = size-1;
  int i = dp[mask]-1;
  while (mask != 0) {
    int old_mask = mask;
    mask = parent[mask];
    int project = find_bit(old_mask ^ mask);
    int need = dp[old_mask] - dp[mask];
    
    // cout << bitset<MAX_M>(mask) << " require: " << need << endl;
    while (need-- > 0) {
      ans[project].push_back(programmers[i].second);
      i--;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < m; ++i) {
    cout << ans[i].size() << " ";
    for (int p : ans[i]) cout << p << " ";
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
