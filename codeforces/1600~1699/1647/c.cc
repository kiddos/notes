#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  if (s[0][0] == '1') {
    cout << "-1" << endl;
    return;
  }

  vector<array<int,4>> ans;
  for (int i = n-1; i >= 0; --i) {
    for (int j = m-1; j >= 0; --j) {
      if (s[i][j] == '1') {
        if (j == 0) {
          ans.push_back({i, j+1, i+1, j+1});
        } else {
          ans.push_back({i+1, j, i+1, j+1});
        }
      }
    }
  }

  cout << ans.size() << endl;
  for (auto a : ans) {
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
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
