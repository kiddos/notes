#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < m && b[j] != a[i]) {
      j++;
    }
    if (j >= m) {
      cout << i << endl;
      return;
    }
    j++;
  }
  cout << n << endl;
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
