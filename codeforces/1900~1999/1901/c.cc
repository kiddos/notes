#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<i64> c = a;
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  if (c.size() == 1) {
    cout << "0" << endl;
    return;
  }

  i64 x = c[0], y = c.back();
  vector<int> ans;
  while (x != y) {
    int p = x % 2;
    ans.push_back(p);
    x = (x+p) / 2;
    y = (y+p) / 2;
  }

  cout << ans.size() << endl;
  if ((int)ans.size() <= n) {
    for (int a : ans) cout << a << " ";
    cout << endl;
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
