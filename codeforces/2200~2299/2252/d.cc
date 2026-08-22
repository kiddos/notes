#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool same_parity(i64 x, i64 y) {
  int p1 = abs(x) % 2;
  int p2 = abs(y) % 2;
  return p1 == p2;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> d;
  for (int i = 0; i < n-1; ++i) {
    d.push_back(a[i+1] - a[i]);
  }

  int m = d.size();
  int idx = 0;
  while (idx < m) {
    int j = idx;
    while (j+1 < m && same_parity(d[j], d[j+1])) {
      j++;
    }
    int l = idx, r = j;
    sort(d.begin() + l, d.begin() + r + 1);
    idx = j+1;
  }

  // for (int i = 0; i < m; ++i) {
  //   cout << d[i] << " ";
  // }
  // cout << endl;

  vector<i64> ans = {a[0]};
  for (int i = 0; i < m; ++i) {
    ans.push_back(ans.back() + d[i]);
  }

  for (int i = 0; i < n; ++i) {
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
