#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int, int> c;
  for (int i = 0; i < n; ++i) c[a[i]]++;

  vector<pair<int,int>> d(c.begin(), c.end());
  sort(d.begin(), d.end(), [&](auto& p1, auto& p2) {
    return p1.second > p2.second;
  });

  if (d.size() == 1) {
    cout << "-1" << endl;
    return;
  }

  int ans = numeric_limits<int>::max();
  int x = d[0].first;
  for (int i = 0, len = 0; i <= n; ++i) {
    if (i == n || a[i] != x) {
      ans = min(ans, len);
      len = 0;
    } else {
      len++;
    }
  }

  if (ans == numeric_limits<int>::max()) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
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
