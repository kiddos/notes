#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a) {
  int n = a.size();
  int l = 0, r = n-1;
  while (l < n && a[l]) l++;
  while (r >= 0 && a[r]) r--;
  if (r < l) return 0;
  return r-l + 2;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t -- > 0) {
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
