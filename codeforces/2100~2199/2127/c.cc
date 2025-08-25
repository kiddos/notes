#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
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
    p.push_back({a[i], b[i]});
  }
  sort(p.begin(), p.end());
  i64 min_add = numeric_limits<i64>::max();
  for (int i = 1; i < n; ++i) {
    auto [ai, bi] = p[i-1];
    auto [aj, bj] = p[i];
    i64 current = abs(ai - bi) + abs(aj - bj);
    vector<int> s = {ai, aj, bi, bj};
    sort(s.begin(), s.end());
    i64 new_val = s[2] - s[0] + s[3] - s[1];
    i64 add = new_val - current;
    min_add = min(min_add, add);
  }
  i64 ans = min_add;
  for (int i = 0; i < n; ++i) {
    auto [ai, bi] = p[i];
    ans += abs(ai - bi);
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
