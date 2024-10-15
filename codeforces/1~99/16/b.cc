#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<i64,i64>> containers;
  for (int i = 0; i < m; ++i) {
    i64 a = 0, b = 0;
    cin >> a >> b;
    containers.emplace_back(b, a);
  }
  sort(containers.rbegin(), containers.rend());

  i64 ans = 0;
  for (int i = 0; i < m && n > 0; ++i) {
    i64 take = min(containers[i].second, (i64) n);
    ans += take * containers[i].first;
    n -= take;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
