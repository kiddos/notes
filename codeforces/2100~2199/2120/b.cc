#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, s = 0;
  cin >> n >> s;
  vector<int> dx(n), dy(n), x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> dx[i] >> dy[i] >> x[i] >> y[i];
  }
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (dx[i] == 1 && dy[i] == 1) {
      ans += x[i] == y[i];
    } else if (dx[i] == -1 && dy[i] == -1) {
      ans += x[i] == y[i];
    } else if (dx[i] == 1 && dy[i] == -1) {
      ans += x[i] == s - y[i];
    } else if (dx[i] == -1 && dy[i] == 1) {
      ans += x[i] == s - y[i];
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
