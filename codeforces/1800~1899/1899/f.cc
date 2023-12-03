#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;

  for (int i = 1; i < n; ++i) {
    cout << i << " " << i+1 << endl;
  }

  int v = n-1;
  for (int i = 0; i < q; ++i) {
    int d = 0;
    cin >> d;
    int v2 = d;
    if (v2 == v) {
      cout << "-1 -1 -1" << endl;
    } else {
      cout << n << " " << v << " " << v2 << endl;
      v = v2;
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
