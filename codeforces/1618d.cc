#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a, int k) {
  int n = a.size();
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = n-1; i >= n-k; --i) {
    ans += a[i-k] / a[i];
  }
  for (int i = 0; i < n-k*2; ++i) ans += a[i];
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = solve(a, k);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
