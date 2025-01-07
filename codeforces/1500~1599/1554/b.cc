#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  i64 ans = numeric_limits<i64>::min();
  int min_index = max(n-k*2, 1);
  for (int i = n; i >= min_index; --i) {
    for (int j = i-1; j >= min_index; --j) {
      ans = max(ans, (i64)i * j - (i64)k * (a[i] | a[j]));
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
