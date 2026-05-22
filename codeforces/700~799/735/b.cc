#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, n1 = 0, n2 = 0;
  cin >> n >> n1 >> n2;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  if (n1 > n2) {
    swap(n1, n2);
  }
  i64 sum1 = 0;
  for (int i = 0; i < n1; ++i) {
    sum1 += a[i];
  }
  i64 sum2 = 0;
  for (int i = n1; i < n1 + n2; ++i) {
    sum2 += a[i];
  }
  double ans = (double)sum1 / n1 + (double)sum2 / n2;
  cout << fixed << setprecision(6) << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
