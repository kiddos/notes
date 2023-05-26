#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int g = 0;
  for (int i = 1; i <= n; ++i) {
    g = gcd(g, a[i]);
  }

  if (g == 1) {
    cout << "0" << endl;
    return;
  }

  if (gcd(g, n) == 1) {
    cout << "1" << endl;
    return;
  }
  if (gcd(g, n-1) == 1) {
    cout << "2" << endl;
    return;
  }
  cout << "3" << endl;
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
