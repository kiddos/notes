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

  sort(a.rbegin(), a.rend());
  int sum = 0;
  int ans = k;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    if (sum > k) {
      break;
    }
    ans = min(ans, k - sum);
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
