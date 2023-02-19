#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& a, int l, int r, int k) {
  sort(a.begin(), a.end());
  int ans = 0;
  for (int aa : a) {
    if (aa >= l && aa <= r) {
      if (k >= aa) {
        k -= aa;
        ans++;
      }
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0, l = 0, r = 0, k = 0;
    cin >> n >> l >> r >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = solve(a, l, r, k);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
