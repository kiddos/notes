#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i+5 <= n && s.substr(i, 5) == "mapie") {
      ans++;
      i += 4;
    } else if (i+3 <= n && s.substr(i, 3) == "map") {
      ans++;
      i += 2;
    } else if (i+3 <= n && s.substr(i, 3) == "pie") {
      ans++;
      i += 2;
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
