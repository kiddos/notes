#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a) {
  int ans = 0;
  for (int aa : a) ans = ans | aa;
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
  }
  cout << flush;
  return 0;
}
