#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  constexpr int INF = numeric_limits<int>::max();
  vector<int> s = {INF}, t = {INF};
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > s.back() && a[i] > t.back()) {
      ans++;
      if (s.back() < t.back()) {
        s.push_back(a[i]);
      } else {
        t.push_back(a[i]);
      }
    } else {
      if (a[i] <= s.back() && a[i] <= t.back()) {
        if (s.back() < t.back()) {
          s.push_back(a[i]);
        } else {
          t.push_back(a[i]);
        }
      } else if (a[i] <= s.back()) {
        s.push_back(a[i]);
      } else if (a[i] <= t.back()) {
        t.push_back(a[i]);
      }
    }
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
