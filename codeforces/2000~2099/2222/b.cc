#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> x(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i];
    x[i]--;
  }
  vector<vector<i64>> values(2);
  for (int i = 0; i < n; ++i) {
    int p = i % 2;
    values[p].push_back(a[i]);
  }
  for (int p = 0; p < 2; ++p) {
    sort(values[p].begin(), values[p].end());
  }
  vector<int> remove(2);
  for (int i = 0; i < m; ++i) {
    remove[x[i]%2]++;
  }
  i64 ans = 0;
  for (int p = 0; p < 2; ++p) {
    if (remove[p] > 0) {
      values[p].pop_back();
      remove[p]--;
      while (remove[p] > 0 && !values[p].empty() && values[p].back() > 0) {
        values[p].pop_back();
        remove[p]--;
      }
    }
    // for (i64 val : values[p]) {
    //   cout << val << " ";
    // }
    // cout << endl;
    ans += accumulate(values[p].begin(), values[p].end(), 0LL);
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
