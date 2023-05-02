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
    vector<int> bits(32);
    for (int b = 0; b < 32; ++b) {
      bool has_one = false, has_zero = false;
      for (int i = 0; i < n; ++i) {
        if (a[i] & (1<<b)) {
          has_one = true;
        } else {
          has_zero = true;
        }
      }
      if (has_one && has_zero) {
        ans |= (1<<b);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
