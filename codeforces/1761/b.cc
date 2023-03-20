#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (n <= 1) {
    cout << n << endl;
    return;
  }

  bool special = true;
  int v1 = a[0], v2 = a[1];
  for (int i = 2; i < n; i += 2) {
    if (a[i] != v1 || a[i+1] != v2) {
      special = false;
      break;
    }
  }

  if (special) {
    cout << (n-2) / 2 + 2 << endl;
  } else {
    cout << n << endl;
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
