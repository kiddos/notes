#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  set<int> x1, x2;
  for (int i = 0; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    if (y == 0) {
      x1.insert(x);
    } else {
      x2.insert(x);
    }
  }

  i64 ans = 0;
  for (int x : x1) {
    if (x2.count(x)) {
      ans += n - 2;
    }
  }
  for (int x : x1) {
    if (x2.count(x-1) && x2.count(x+1)) {
      ans++;
    }
  }
  for (int x : x2) {
    if (x1.count(x-1) && x1.count(x+1)) {
      ans++;
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
