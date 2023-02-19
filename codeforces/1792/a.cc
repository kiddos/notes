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
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    sort(h.begin(), h.end());
    int ans = 0;
    for (int i = 0; i < n;) {
      if (i+1 < n && h[i] == 1 && h[i+1] == 1) {
        ans++;
        i += 2;
      } else {
        ans++;
        i++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
