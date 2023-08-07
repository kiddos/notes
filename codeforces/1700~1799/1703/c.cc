#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 0; i < n; ++i) {
    int m = 0;
    cin >> m;
    string b;
    cin >> b;
    for (int j = 0; j < m; ++j) {
      if (b[j] == 'U') {
        a[i] = (a[i] - 1 + 10) % 10;
      } else if (b[j] == 'D') {
        a[i] = (a[i] + 1) % 10;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
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
