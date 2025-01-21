#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int k = 0;
  vector<int> ans(2 * n);
  for (int i = 0; i < n * 2; i += 2, ++k) {
    ans[i] = a[k];
  }
  for (int i = 1; i < n * 2; i += 2, ++k) {
    ans[i] = a[k];
  }
  for (int i = 0; i < n * 2; ++i) {
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
