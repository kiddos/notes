#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<i64,i64>> p;
  for (int i = 0; i < n; ++i) {
    p.emplace_back(a[i], 1);
  }
  int i = 0;
  while (i < (int)p.size()) {
    if (p[i].first % x == 0) {
      p.emplace_back(p[i].first / x, p[i].second * x);
    } else {
      break;
    }
    i++;
  }

  i64 ans = 0;
  for (int i = 0; i < (int)p.size(); ++i) {
    ans += p[i].first * p[i].second;
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
