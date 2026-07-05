#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  i64 min_val = *min_element(a.begin(), a.end());
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    i64 diff = a[i] - min_val;
    if (diff % k != 0) {
      cout << "-1" << endl;
      return;
    }
    ans += diff / k;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
