#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  set<i64> s = {0};
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      sum += a[i];
    } else {
      sum -= a[i];
    }
    if (s.count(sum)) {
      cout << "YES" << endl;
      return;
    }

    s.insert(sum);
  }

  cout << "NO" << endl;
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
