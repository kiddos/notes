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
  i64 max_so_far = a[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] >= max_so_far) {
      max_so_far = a[i];
    } else {
      max_so_far = a[i] + max_so_far;
    }
  }
  cout << max_so_far << endl;
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
