#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  vector<int> ans;
  for (int i = n; i >= k; --i) {
    ans.push_back(i);
  }
  for (int i = m+1; i < k; ++i) {
    ans.push_back(i);
  }
  for (int i = 1; i <= m; ++i) {
    ans.push_back(i);
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
