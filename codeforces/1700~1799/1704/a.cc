#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;

  if (m > n) {
    cout << "NO" << endl;
    return;
  }

  if (a == b) {
    cout << "YES" << endl;
    return;
  }

  int diff = n - m;
  for (int i = 0; i < diff; ++i) {
    if (a[i] != b[0] && a[i+1] != b[0]) {
      continue;
    } else {
      a[i+1] = b[0];
    }
  }

  if (a.substr(diff) == b) {
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
