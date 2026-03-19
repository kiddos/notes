#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int s = 0, k = 0, m = 0;
  cin >> s >> k >> m;
  int ans = 0;
  if (k >= s) {
    int last_measure = m % k;
    ans = max(s - last_measure, 0);
  } else {
    // s -> (s-k) -> s -> s-k
    int last_measure = m % k;
    int flips = m / k;
    if (flips % 2 == 1) {
      ans = max(k - last_measure, 0);
    } else {
      ans = max(s - last_measure, 0);
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
