#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 0;
    int parity = a[0] % 2;
    for (int i = 1; i < n; ++i) {
      int p = a[i] % 2;
      if (p == parity) {
        ans++;
      }
      parity = p;
    }
    cout << ans << endl;
  }
  return 0;
}
