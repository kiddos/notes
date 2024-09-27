#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<pair<i64, int>> s;
  for (int i = 0; i < n; ++i) {
    i64 sum = a[i];
    int count = 1;
    while (!s.empty() && s.back().first > sum / count) {
      auto [s2, c2] = s.back();
      s.pop_back();
      sum += s2 * c2;
      count += c2;
    }
    int size2 = sum % count;
    int size1 = count - size2;
    s.emplace_back(sum / count, size1);
    s.emplace_back(sum / count + 1, size2);
  }

  // for (auto& [x, c] : s) {
  //   cout << x << "," << c << "  ";
  // }
  // cout << endl;
  while (!s.empty() && s.back().second == 0) {
    s.pop_back();
  }

  i64 max_val = s.back().first;
  i64 min_val = s[0].first;
  i64 ans = max_val - min_val;
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
