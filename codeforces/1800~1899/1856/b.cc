#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (n == 1) {
    cout << "NO" << endl;
    return;
  }

  int ones = 0;
  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ones++;
    } else {
      sum += a[i] - 1;
    }
  }

  if (sum >= ones) {
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
