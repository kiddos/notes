#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  int m = n * 3;
  vector<pair<int,int>> ops;
  for (int i = 1, j = m; i <= j; i += 3, j -= 3) {
    ops.push_back({i, j});
  }

  cout << ops.size() << endl;
  for (auto& [i, j] : ops) cout << i << " " << j << endl;
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
