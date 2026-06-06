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
  vector<int> l(m), r(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i];
  }
  vector<int> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }

  i64 ans = 0;
  for (int i = 0; i < m; ++i) {
    int sum = p[r[i]] - p[l[i]-1];
    if (sum > 0) {
      ans += sum;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
