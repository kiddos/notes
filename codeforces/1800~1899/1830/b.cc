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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(a[i], b[i]);
  }
  sort(p.begin(), p.end());

  i64 ans = 0;
  map<i64, unordered_map<int,int>> a2b;
  for (auto& [ai, bi] : p) {
    for (auto& [aj, b_map] : a2b) {
      if (aj * ai - bi > n) {
        break;
      }
      int p = aj * ai;
      int bj = p - bi;
      if (b_map.count(bj)) {
        ans += b_map[bj];
      }
    }
    a2b[ai][bi]++;
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
