#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int max_peak = (n-1) / 2;
  if (k > max_peak) {
    cout << "-1" << endl;
    return;
  }

  vector<int> ans(n);
  int x = n;
  for (int i = 1; i < n && k > 0; i += 2, --k) {
    ans[i] = x--;
  }
  for (int i = n-1; i >= 0; --i) {
    if (ans[i] == 0) {
      ans[i] = x--;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
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
