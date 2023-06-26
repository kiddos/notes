#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  if (a == b) {
    cout << "YES" << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      cout << "NO" << endl;
      return;
    }
  }

  for (int i = 0; i < n ; ++i) {
    if (b[i] > b[(i+1)%n]+1 && a[i] < b[i]) {
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
