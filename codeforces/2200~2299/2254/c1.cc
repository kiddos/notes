#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<string> c(2), d(2);
  for (int i = 0; i < n; ++i) {
    int p = i%2;
    c[p].push_back(a[i]);
    d[p].push_back(b[i]);
  }
  for (int p = 0; p < 2; ++p) {
    sort(c[p].begin(), c[p].end());
    sort(d[p].begin(), d[p].end());
  }

  if (c[0] == d[0] && c[1] == d[1]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
