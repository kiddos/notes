#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> words(n);
  for (int i = 0; i < n; ++i) cin >> words[i];

  int ans = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int diff = 0;
      for (int k = 0; k < m; ++k) {
        diff += abs(words[i][k] - words[j][k]);
      }

      ans = min(ans, diff);
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
