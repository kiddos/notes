#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 m = 0, k = 0;
  cin >> n >> m >> k;

  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int pick = (k + m - 1) / m;
  vector<pair<int,int>> p;
  for (int i = 1; i <= n; ++i) {
    p.emplace_back(a[i], i);
  }
  sort(p.begin(), p.end());
  p.resize(pick);

  i64 total = k;
  for (int i = 0; i < pick; ++i) {
    int take = min(total, m);
    p[i].first = take;
    total -= take;
  }
  sort(p.begin(), p.end(), [&](auto& p1, auto& p2) {
    return p1.second < p2.second;
  });

  i64 ans = 0;
  i64 bought = 0;
  for (auto& [take, i] : p) {
    i64 cost = (a[i] + bought) * take;
    ans += cost;
    bought += take;
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
