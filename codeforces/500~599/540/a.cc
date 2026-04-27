#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int d1 = s[i] - '0';
    int d2 = t[i] - '0';
    int step = min({abs(d1 - d2), 10 - d1 + d2, d1 + 10 - d2});
    ans += step;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
