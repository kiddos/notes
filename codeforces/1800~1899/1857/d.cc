#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  vector<i64> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = a[i] - b[i];
  }

  i64 max_val = *max_element(c.begin(), c.end());
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (c[i] == max_val) {
      ans.push_back(i+1);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
