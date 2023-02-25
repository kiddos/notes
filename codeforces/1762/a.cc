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

    int total = accumulate(a.begin(), a.end(), 0);
    if (total % 2 == 0) {
      cout << "0" << endl;
    } else {
      int ans = numeric_limits<int>::max();
      for (int num : a) {
        int mod = num % 2;
        int x = 0;
        while (num > 0 && num % 2 == mod) {
          num >>= 1;
          x++;
        }
        ans = min(ans, x);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
