#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int xc = 0, yc = 0, k = 0;
  cin >> xc >> yc >> k;

  vector<pair<int,int>> ans;
  for (int i = 0; i < k/2; ++i) {
    ans.push_back({xc - (i+1), yc});
    ans.push_back({xc + (i+1), yc});
  }
  if (k % 2 == 1) {
    ans.push_back({xc, yc});
  }
  for (auto& [x, y] : ans) {
    cout << x << " " << y << endl;
  }
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
