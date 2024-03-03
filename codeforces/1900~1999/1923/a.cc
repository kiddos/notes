#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int sum = accumulate(a.begin(), a.end(), 0);
  if (sum == 0) {
    cout << "0" << endl;
    return;
  }

  int l = 0;
  while (l < n && a[l] == 0) l++;
  int r = n-1;
  while (r >= 0 && a[r] == 0) r--;
  int len = r - l + 1;
  int ans = len - sum;
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
