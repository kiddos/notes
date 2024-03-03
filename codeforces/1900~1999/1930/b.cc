#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> ans(n);
  for (int i = 0, k = 1; i < n; i += 2, k += 2) {
    ans[i] = k;
  }
  for (int i = n-1-n%2, k = 2; i >= 0; i -= 2, k += 2) {
    ans[i] = k;
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << endl;
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
