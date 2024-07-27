#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  i64 ans = 0;
  i64 sum = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    sum += a[i];
    while (j <= i && (a[i] - a[j] > 1 || sum > m)) {
      sum -= a[j++];
    }
    ans = max(ans, sum);
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
