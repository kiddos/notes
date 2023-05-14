#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; ++i) cin >> d[i];

  vector<int> a = d;
  for (int i = 1; i < n; ++i) {
    if (a[i] != 0 && a[i-1] - a[i] >= 0) {
      cout << "-1" << endl;
      return;
    }
    a[i] = a[i-1] + a[i];
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
