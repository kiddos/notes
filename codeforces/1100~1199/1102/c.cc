#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0, y = 0;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (x > y) {
    cout << n << endl;
    return;
  }

  int single_break = 0;
  for (int i = 0; i < n; ++i) {
    if (x >= a[i]) {
      single_break++;
    }
  }
  int ans = (single_break + 1) / 2;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
