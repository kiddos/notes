#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, d = 0;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = 0;
  cin >> m;

  sort(a.begin(), a.end());
  int ans = 0;
  int k = m;
  for (int i = 0; i < n && k > 0; ++i, --k) {
    ans += a[i];
  }
  ans -= k * d;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
