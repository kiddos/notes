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
  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<int> c;
  for (auto [x, x_count] : count) {
    c.push_back(x_count);
  }
  sort(c.begin(), c.end());
  vector<int> p = {0};
  int m = c.size();
  for (int i = 0; i < m; ++i) {
    p.push_back(p.back() + c[i]);
  }
  int ans = numeric_limits<int>::max();
  for (int i = 0; i < m; ++i) {
    int remove_large = p.back() - p[i] - (m-i) * c[i];
    int remove_small = p[i];
    ans = min(ans, remove_large + remove_small);
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
