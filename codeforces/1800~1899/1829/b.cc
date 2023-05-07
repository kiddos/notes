#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  int z = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    if (a == 0) {
      z++;
    } else {
      z = 0;
    }
    ans = max(ans, z);
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
