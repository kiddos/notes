#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0, y = 0;
  cin >> n >> x >> y;
  string s;
  cin >> s;

  if (abs(x) > n || abs(y) > n) {
    cout << "NO" << endl;
    return;
  }

  vector<pair<int,int>> corners = {{n, n}, {-n, n}, {n, -n}, {-n, -n}};
  int four = 0;
  for (int i = 0 ; i < n; ++i) {
    four += s[i] == '4';
  }

  int outside = four-1;
  for (auto [cx, cy] : corners) {
    int dist = abs(x - cx) + abs(y - cy);
    if (dist <= outside) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
