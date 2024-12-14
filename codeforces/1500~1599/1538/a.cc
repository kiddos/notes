#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int i1 = max_element(a.begin(), a.end()) - a.begin();
  int i2 = min_element(a.begin(), a.end()) - a.begin();
  int ans1 = max(i1, i2) + 1;
  int ans2 = n - min(i1, i2);
  int ans3 = min(i1, i2) + 1 + n - max(i1, i2);
  int ans = min({ans1, ans2, ans3});
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
