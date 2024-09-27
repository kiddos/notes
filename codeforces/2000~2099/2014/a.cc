#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int robin = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= k) {
      robin += a[i];
    } else if (a[i] == 0) {
      if (robin > 0) {
        robin--;
        ans++;
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
