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
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  deque<i64> c(b.begin(), b.end());
  i64 ans = 0;
  for (int p = 0; p < n; ++p) {
    i64 min_diff = numeric_limits<i64>::max();
    int k = 0;
    for (i64 x : c) {
      min_diff = min(min_diff, abs(x - a[k++]));
    }
    ans = max(ans, min_diff);
    c.push_front(c.back());
    c.pop_back();
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
