#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int p = 0, q = 0;
    cin >> p >> q;
    ans += p <= q-2;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
