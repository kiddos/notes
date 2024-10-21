#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> p(n+1);
  p[1] = 2;
  for (int i = 2; i <= n; ++i) {
    p[i] = p[i-1] * 2LL;
  }

  i64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += p[i];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
