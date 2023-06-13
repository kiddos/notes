#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (n == 1) {
    cout << "0" << endl;
    return;
  }

  int ans = a.back() - *min_element(a.begin(), prev(a.end()));
  ans = max(ans, *max_element(a.begin()+1, a.end()) - a[0]);
  for (int i = 0; i < n; ++i) {
    ans = max(ans, a[i] - a[(i+1)%n]);
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
