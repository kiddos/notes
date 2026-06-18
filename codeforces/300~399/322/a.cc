#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> ans;
  for (int i = 1; i <= n; ++i) {
    ans.push_back({i, 1});
  }
  for (int j = 2; j <= m; ++j) {
    ans.push_back({1, j});
  }
  cout << ans.size() << endl;
  for (auto [i,j] : ans) {
    cout << i << " " << j << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
