#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> t(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }
  vector<vector<int>> group(4);
  for (int i = 1; i <= n; ++i) {
    group[t[i]].push_back(i);
  }
  vector<array<int,3>> ans;
  size_t idx = 0;
  while (idx < group[1].size() && idx < group[2].size() && idx < group[3].size()) {
    ans.push_back({group[1][idx], group[2][idx], group[3][idx]});
    idx++;
  }
  cout << ans.size() << endl;
  for (auto [i1, i2, i3] : ans) {
    cout << i1 << " " << i2 << " " << i3 << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
