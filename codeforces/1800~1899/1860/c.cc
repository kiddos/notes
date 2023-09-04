#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  int ans = 0;
  set<int> lose, win;
  for (int i = 0; i < n; ++i) {
    auto it = win.upper_bound(p[i]);
    if (it != win.begin()) {
      lose.insert(p[i]);
    } else {
      it = lose.upper_bound(p[i]);
      if (it != lose.begin()) {
        win.insert(p[i]);
        ans++;
      } else {
        lose.insert(p[i]);
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
