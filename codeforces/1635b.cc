#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a) {
  int n = a.size();
  int ans = 0;
  for (int i = 1; i < n-1; ++i) {
    if (a[i] > a[i-1] && a[i] > a[i+1]) {
      if (i + 2 < n) {
        a[i+1] = max(a[i], a[i+2]);
      } else {
        a[i+1] = a[i];
      }
      ans++;
    }
  }
  return ans;
}

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
    int ans = solve(a);
    cout << ans << '\n';
    for (int aa : a) cout << aa << ' ';
    cout << '\n';
  }
  cout << flush;
  return 0;
}
