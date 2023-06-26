#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int count = 0;
  int mode = 0;
  for (int i = 1; i < n; ++i) {
    if (mode == 0) {
      if (a[i] < a[i-1]) {
        mode = 1;
        count++;
      }
    } else {
      if (a[i] > a[i-1]) {
        mode = 0;
        count++;
      }
    }
  }

  if (count <= 1) {
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
