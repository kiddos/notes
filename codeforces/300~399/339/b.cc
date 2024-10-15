#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  int current = 1;
  i64 ans = 0;
  for (int i = 0; i < m; ++i) {
    if (a[i] >= current) {
      ans += a[i] - current;
      current = a[i];
    } else {
      ans += n - current + 1 + a[i] - 1;
      current = a[i];
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
