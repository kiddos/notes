#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  if (k <= 1) {
    // no graph can have -1 diameter
    cout << "NO" << endl;
  } else if (k == 2) {
    // only n=1 can have 0 diameter
    if (n == 1 && m == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (k == 3) {
    // complete graph
    i64 edges = n * (n-1) / 2;
    if (m == edges) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    i64 min_require = n-1;
    i64 max_edges = n * (n-1) / 2;
    if (m >= min_require && m <= max_edges) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
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
