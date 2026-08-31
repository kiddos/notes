#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) {
      i64 to_add = b[i] - a[i];
      a[i] += to_add;
      if (i+1 < n) {
        a[i+1] -= to_add;
      }
    } else if (b[i] < a[i]) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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
