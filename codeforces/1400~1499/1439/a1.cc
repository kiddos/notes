#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<array<int,6>> ans;
  auto remove = [&](int i, int j) {
    int i1 = i, i2 = i+1 < n ? i+1 : i-1;
    int j1 = j, j2 = j+1 < m ? j+1 : j-1;
    ans.push_back({i1, j1, i1, j2, i2, j1});
    ans.push_back({i2, j1, i1, j1, i2, j2});
    ans.push_back({i1, j2, i1, j1, i2, j2});
  };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '1') {
        remove(i, j);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto r : ans) {
    for (int k = 0; k < 6; ++k) {
      cout << r[k]+1 << " ";
    }
    cout << endl;
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
