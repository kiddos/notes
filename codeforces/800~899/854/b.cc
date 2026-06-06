#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;

  i64 min_count = (k == 0 || k == n) ? 0 : 1;
  i64 max_count = min(n - k, k * 2);

  cout << min_count << " " << max_count << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
