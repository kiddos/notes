#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  constexpr i64 inf = 1e18;
  multiset<int> up, right;
  i64 right_total = 0, up_total = 0;
  i64 right_cost = inf, up_cost = inf;
  i64 ans = inf;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      right.insert(c[i]);
      right_total += c[i];
      int min_count = n - right.size() + 1;
      i64 min_val = *right.begin();
      right_cost = (right_total - min_val) + min_val * min_count;
    } else {
      up.insert(c[i]);
      up_total += c[i];
      int min_count = n - up.size() + 1;
      i64 min_val = *up.begin();
      up_cost = (up_total - min_val) + min_val * min_count;
    }
    ans = min(ans, right_cost + up_cost);
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
