#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  vector<int> dist(4);
  for (int i = 0; i < 4; ++i) cin >> dist[i];

  int ans = 0;
  for (int i = 1; i < 4; ++i) {
    ans += dist[i] > dist[0];
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
