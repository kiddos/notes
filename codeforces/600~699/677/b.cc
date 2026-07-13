#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 h = 0, k = 0;
  cin >> n >> h >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int idx = 0;
  i64 current = 0;
  i64 ans = 0;
  while (idx < n) {
    bool add = false;
    while (idx < n && current + a[idx] <= h) {
      current += a[idx];
      idx++;
      add = true;
    }
    if (!add) {
      ans += (current + k-1) / k;
      current = 0;
    } else {
      ans += current / k;
      current %= k;
    }
  }
  if (current > 0) {
    ans += (current + k-1) / k;
    current = 0;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
