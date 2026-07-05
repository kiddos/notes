#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = 0;
  cin >> m;
  vector<int> p(m), s(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i] >> s[i];
  }
  map<int,int> endure;
  for (int i = 0; i < m; ++i) {
    endure[p[i]] = max(endure[p[i]], s[i]);
  }
  for (auto it = next(endure.rbegin()); it != endure.rend(); ++it) {
    auto it2 = prev(it);
    it->second = max(it->second, it2->second);
  }

  // for (auto it = endure.begin(); it != endure.end(); ++it) {
  //   cout << it->first << " , " << it->second << endl;
  // }

  int L = log2(n)+1;
  vector<vector<int>> binary_lift(L, vector<int>(n));
  binary_lift[0] = a;
  for (int l = 1; l < L; ++l) {
    int offset = 1<<(l-1);
    for (int i = 0; i < n-offset; ++i) {
      binary_lift[l][i] = max(binary_lift[l-1][i], binary_lift[l-1][i+offset]);
    }
  }

  auto query_max = [&](int l, int r) -> int {
    int len = r-l+1;
    int p2 = 1;
    int p = 0;
    while (p2*2 <= len) {
      p2 *= 2;
      p++;
    }
    int i1 = l, i2 = r-p2+1;
    // cout << l << "~" << r << " range max=" << max(binary_lift[p][i1], binary_lift[p][i2]) << ", p=" << p << endl;
    return max(binary_lift[p][i1], binary_lift[p][i2]);
  };

  vector<int> can_defeat(n);
  for (int i = 0; i < n; ++i) {
    int l = i, r = n-1;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int range_max = query_max(i, mid);
      int len = mid-i+1;
      auto it = endure.lower_bound(range_max);
      if (it->second >= len) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    if (idx < 0) {
      cout << "-1" << endl;
      return;
    }
    can_defeat[i] = idx;
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << can_defeat[i] << " ";
  // }
  // cout << endl;

  int idx = 0;
  int ans = 0;
  while (idx < n) {
    int idx2 = can_defeat[idx];
    ans++;
    idx = idx2+1;
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
