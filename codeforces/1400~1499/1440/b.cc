#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int m = n * k;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int larger = n / 2;
  i64 ans = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < larger; ++j) {
      a.pop_back();
    }
    ans += a.back();
    a.pop_back();
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
