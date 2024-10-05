#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> conveyor(n);
  for (int i = 0; i < n; ++i) {
    cin >> conveyor[i];
  }
  int ans = 0;
  for (int i = 0; i < n-1; ++i) {
    if (conveyor[i].back() != 'D') {
      ans++;
    }
  }
  for (int j = 0; j < m-1; ++j) {
    if (conveyor.back()[j] != 'R') {
      ans++;
    }
  }
  cout << ans << endl;
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
