#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, s = 0;
  cin >> n >> s;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  int ans = 0;
  int add = 0;
  if (x[0] <= s) {
    ans += s - x[0];
    add++;
  }
  if (x.back() > s) {
    ans += x.back() - s;
    add++;
  }
  if (add == 2) {
    ans += min(x.back() - s, s - x[0]);
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
