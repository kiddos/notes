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
  int m = 0;
  cin >> m;
  vector<int> q(m);
  for (int i = 0; i < m; ++i) {
    cin >> q[i];
  }
  vector<i64> starting(n+1);
  starting[0] = 1;
  for (int i = 0; i < n; ++i) {
    starting[i+1] = starting[i] + a[i];
  }
  vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    auto it = upper_bound(starting.begin(), starting.end(), q[i]);
    int idx = it - starting.begin();
    ans[i] = idx;
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
