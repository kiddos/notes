#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int,int> counts;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 2 || a[i] == 1) {
      ans += counts[2];
      counts[2]++;
    } else {
      ans += counts[a[i]];
      counts[a[i]]++;
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
