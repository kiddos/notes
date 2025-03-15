#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> c(2);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '-') {
      c[0]++;
    } else if (s[i] == '_') {
      c[1]++;
    }
  }
  if (c[0] <= 1) {
    cout << "0" << endl;
  } else {
    i64 p0 = c[0] / 2;
    i64 p1 = c[0] - p0;
    i64 p2 = c[1];
    i64 ans = p0 * p1 * p2;
    cout << ans << endl;
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
