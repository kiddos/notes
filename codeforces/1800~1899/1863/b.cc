#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<int> index(n+1);
  for (int i = 1; i <= n; ++i) index[a[i]] = i;

  int ans = 0;
  int last = index[1];
  for (int i = 2; i <= n; ++i) {
    if (index[i] < last) {
      ans++;
    }
    last = index[i];
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
