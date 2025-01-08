#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0;
  cin >> n >> m;

  // find the smallest k such that n ^ k >= m + 1
  i64 k = 0;
  i64 m2 = m+1;
  for (int b = 30; b >= 0 && n < m2; --b) {
    i64 mask = 1LL << b;
    i64 b1 = (n & mask), b2 = (m2 & mask);
    if (b1 && b2) {
      continue;
    } else if (b1) {
      continue;
    } else if (b2) {
      k |= mask;
      n |= mask;
    }
  }
  cout << k << endl;
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
