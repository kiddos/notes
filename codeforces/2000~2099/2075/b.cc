#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 ans = 0;
  if (k == 1) {
    ans = max(ans, (i64) a[0] + *max_element(a.begin()+1, a.end()));
    ans = max(ans, (i64) a.back() + *max_element(a.begin(), a.begin() + n-1));
  } else {
    sort(a.rbegin(), a.rend());
    for (int i = 0; i <= k; ++i) {
      ans += a[i];
    }
  }

  cout << ans << endl;
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
