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

  vector<i64> s;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!s.empty() && s.back() <= a[i]) {
      i64 min_val = s.back();
      i64 add = 0;
      while (!s.empty() && s.back() <= a[i]) {
        s.pop_back();
        if (!s.empty()) {
          add = max(add, s.back() - min_val);
        }
      }
      if (s.empty()) {
        ans += add;
      } else {
        ans += a[i] - min_val;
      }
    }
    s.push_back(a[i]);
  }
  ans += s[0] - s.back();
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
