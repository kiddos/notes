#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

  vector<int> a;
  string ans(n, '0');
  bool decreased = false;
  for (int i = 0; i < n; ++i) {
    if (a.empty()) {
      ans[i] = '1';
      a.push_back(x[i]);
    } else if (x[i] >= a.back()) {
      if (decreased) {
        if (x[i] <= a[0]) {
          ans[i] = '1';
          a.push_back(x[i]);
        }
      } else {
        ans[i] = '1';
        a.push_back(x[i]);
      }
    } else {
      if (!decreased) {
        if (x[i] <= a[0]) {
          decreased = true;
          ans[i] = '1';
          a.push_back(x[i]);
        }
      }
    }
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
