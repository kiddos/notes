#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 a = 0, b = 0, c = 0, m = 0;
  cin >> a >> b >> c >> m;

  i64 sum = a + b + c;
  i64 max_pairs = a-1 + b-1 + c-1;
  i64 min_pairs = max(max({a, b, c}) - (sum - max({a, b, c})) - 1, 0LL);
  if (max_pairs >= m && m >= min_pairs) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
