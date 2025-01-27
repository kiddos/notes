#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<i64> left(n);
  for (int i = 0, sheep = 0; i < n; ++i) {
    if (s[i] == '*') {
      sheep++;
      if (i > 0) left[i] = left[i-1];
    } else {
      left[i] = sheep + (i > 0 ? left[i-1] : 0);
    }
  }
  i64 ans = left[n-1];
  i64 moves = 0;
  for (int i = n-1, sheep = 0; i >= 0; --i) {
    if (s[i] == '*') {
      sheep++;
    } else {
      moves += sheep;
      i64 total = moves + (i > 0 ? left[i-1] : 0);
      ans = min(ans, total);
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
