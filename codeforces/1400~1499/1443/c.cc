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
  vector<pair<int,int>> dish;
  for (int i = 0; i < n; ++i) {
    dish.push_back({a[i], b[i]});
  }

  sort(dish.begin(), dish.end());
  vector<i64> suffix_b(n+1);
  for (int i = n-1; i >= 0; --i) {
    suffix_b[i] = suffix_b[i+1] + dish[i].second;
  }
  i64 ans = suffix_b[0];
  for (int i = 0; i < n; ++i) {
    i64 total = max((i64)dish[i].first, suffix_b[i+1]);
    ans = min(ans, total);
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
