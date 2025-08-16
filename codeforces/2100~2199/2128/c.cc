#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int min_so_far = b[0];
  for (int i = 1; i < n; ++i) {
    int can_use = min_so_far;
    if (b[i] >= can_use * 2) {
      cout << "NO" << endl;
      return;
    }
    min_so_far = min(min_so_far, b[i]);
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
