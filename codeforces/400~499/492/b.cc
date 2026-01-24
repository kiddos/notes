#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, l = 0;
  cin >> n >> l;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  double gap = 0;
  for (int i = 1; i < (int)a.size(); ++i) {
    gap = max(gap, (a[i] - a[i-1]) / 2.0);
  }
  gap = max(gap, (double)a[0]);
  gap = max(gap, (double)l - a.back());
  double ans = gap;
  cout << fixed << setw(6) << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
