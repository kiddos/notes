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
  vector<int> max_val(2), count(2);
  for (int i = 0; i < n; ++i) {
    max_val[i%2] = max(max_val[i%2], a[i]);
    count[i%2]++;
  }
  int ans = max(max_val[0] + count[0], max_val[1] + count[1]);
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
