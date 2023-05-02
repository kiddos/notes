#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n-1);
  for (int i = 0; i < n-1; ++i) cin >> b[i];

  vector<int> index(n-1);
  iota(index.begin(), index.end(), 0);
  sort(index.begin(), index.end(), [&](int i1, int i2) {
    return b[i1] < b[i2];
  });

  vector<int> ans(n, -1);
  for (int idx : index) {
    if (ans[idx] < 0) ans[idx] = b[idx];
    if (ans[idx+1] < 0) ans[idx+1] = b[idx];
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
