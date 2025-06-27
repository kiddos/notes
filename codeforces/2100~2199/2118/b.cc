#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int,3>> ans;
  for (int i = 2; i <= n; ++i) {
    int l = 1, r = i;
    ans.push_back({i, l, r});
  }
  for (int i = 1; i < n-1; ++i) {
    int l = i+1, r = n;
    ans.push_back({i, l, r});
  }
  cout << ans.size() << endl;
  for (auto [i, l, r] : ans) {
    cout << i << " " << l << " " << r << endl;
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
