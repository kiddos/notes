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

  array<int,3> ans = {numeric_limits<int>::max(), 0, 0};
  for (int i = 0; i < n; ++i) {
    array<int,3> value = {abs(a[i] - a[(i-1+n)%n]), i, (i-1+n) %n};
    ans = min(ans, value);
  }
  cout << ans[1]+1 << " " << ans[2]+1 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
