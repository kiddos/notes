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
  sort(a.rbegin(), a.rend());
  i64 sq = 0;
  for (int i = 0; i < n; i += 2) {
    if (i+1 < n) {
      sq += a[i] * a[i] - a[i+1] * a[i+1];
    } else {
      sq += a[i] * a[i];
    }
  }
  double pi = 3.1415926536;
  double ans = sq * pi;
  cout << fixed << setprecision(10) << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
