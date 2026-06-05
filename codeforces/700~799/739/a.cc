#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> l(m), r(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i];
  }
  int min_len = n+1;
  for (int i = 0; i < m; ++i) {
    int len = r[i] - l[i] + 1;
    min_len = min(min_len, len);
  }
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = i % min_len;
  }

  cout << min_len << endl;
  for (int i = 0; i < n; ++i) {
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
