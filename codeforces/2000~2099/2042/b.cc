#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  int max_a = *max_element(c.begin(), c.end());
  vector<int> count_c(max_a+1);
  for (int i = 0; i < n; ++i) {
    count_c[c[i]]++;
  }
  int single = 0;
  int ans = 0;
  for (int i = 1; i <= max_a; ++i) {
    if (count_c[i] == 1) {
      single++;
    } else if (count_c[i] > 1) {
      ans++;
    }
  }
  ans += (single + 1) / 2 * 2;
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
