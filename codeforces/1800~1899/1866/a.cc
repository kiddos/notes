#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int ans = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    ans = min(ans, abs(a));
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
