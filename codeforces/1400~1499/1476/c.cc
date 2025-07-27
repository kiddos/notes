#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i < n; ++i) {
    if (b[i] < a[i]) {
      swap(b[i], a[i]);
    }
  }

  vector<i64> connect_to_ends(n);
  connect_to_ends[0] = b[1] - a[1] + 1;
  connect_to_ends[1] = b[1] - a[1] + 1;
  for (int i = 2; i < n; ++i) {
    if (a[i] != b[i]) {
      connect_to_ends[i] = max(
        b[i] - a[i] + 1,
        connect_to_ends[i-1] + (a[i] - 1) + 1 + (c[i-1] - b[i]) + 1);
    } else {
      connect_to_ends[i] = 1;
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << connect_to_ends[i] << " ";
  // }
  // cout << endl;

  i64 ans = 0;
  for (int i = 1; i < n; ++i) {
    i64 cycle_size = c[i] + connect_to_ends[i];
    ans = max(ans, cycle_size);
    // cout << "i=" << i << ", cycle_size=" << cycle_size << endl;
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
