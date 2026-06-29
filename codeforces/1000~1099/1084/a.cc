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
  int ans = numeric_limits<int>::max();
  for (int x = 0; x < n; ++x) {
    int e = 0;
    for (int i = 0; i < n; ++i) {
      e += (abs(x-i) + i + x + x + i + abs(x-i)) * a[i];
    }
    ans = min(ans, e);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
