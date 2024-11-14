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
  while (m < n && a[m] <= 0) {
    m++;
  }
  vector<pair<int,int>> ans;
  for (int i = m-2; i >= 0; --i) {
    a[i] += a[i+1];
    ans.emplace_back(i, i+1);
  }

  for (int i = m; i+1 < n; ++i) {
    if (a[i+1] < a[i]) {
      while (a[i] < abs(a[i+1])) {
        a[i] += a[i];
        ans.emplace_back(i, i);
      }
      while (a[i+1] < a[i]) {
        a[i+1] += a[i];
        ans.emplace_back(i+1, i);
      }
    }
  }

  // cout << "a:";
  // for (int i = 0; i < n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;

  cout << ans.size() << endl;
  for (auto [i, j] : ans) {
    cout << (i+1) << " " << (j+1) << endl;
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
