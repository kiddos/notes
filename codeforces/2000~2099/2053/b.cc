#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  vector<int> p(2*n+1), c(2*n+1);
  for (int i = 0; i < n; ++i) {
    if (l[i] == r[i]) {
      p[l[i]] = 1;
      c[l[i]]++;
    }
  }
  for (int i = 1; i <= 2*n; ++i) {
    p[i] += p[i-1];
  }

  string ans(n, ' ');
  for (int i = 0; i < n; ++i) {
    if (l[i] == r[i]) {
      if (c[l[i]] == 1) {
        ans[i] = '1';
      } else {
        ans[i] = '0';
      }
    } else {
      int count = p[r[i]] - p[l[i]-1];
      int len = r[i] - l[i] + 1;
      if (count == len) {
        ans[i] = '0';
      } else {
        ans[i] = '1';
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
