#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;

  vector<i64> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  sort(p.begin(), p.end());
  vector<i64> prefix = {0};
  for (int i = 0; i < n; ++i) {
    prefix.push_back(prefix.back() + p[i]);
  }

  while (q-- > 0) {
    int x = 0, y = 0;
    cin >> x >> y;

    i64 ans = prefix[n-x+y] - prefix[n-x];
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
