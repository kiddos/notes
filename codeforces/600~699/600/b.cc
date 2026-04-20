#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    auto it = upper_bound(a.begin(), a.end(), b[i]);
    ans[i] = it - a.begin();
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
