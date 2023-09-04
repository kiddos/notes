#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = numeric_limits<int>::max();
  for (int i = 1; i < n; ++i) {
    int x = max(a[i], a[i-1]);
    int y = min(a[i], a[i-1]);
    if (x >= y * 2) {
      ans = min(ans, (max(a[i], a[i-1]) + 1) / 2);
    } else {
      ans = min(ans, (x + y + 2) / 3);
    }
  }

  for (int i = 2; i < n; ++i) {
    ans = min(ans, (a[i] + a[i-2] + 1) / 2);
  }

  sort(a.begin(), a.end());
  ans = min(ans, (a[0]+1) /2 + (a[1]+1) / 2);

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
