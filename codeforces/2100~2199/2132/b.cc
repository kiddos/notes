#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;

  // n = x + y = x + (x * 10)
  // n = x + y = x + (x * 100)
  vector<i64> ans;
  for (i64 p = 10; p <= n; p = p * 10) {
    i64 base = p + 1;
    if (n % base == 0) {
      ans.push_back(n / base);
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  if (ans.size()) {
    for (i64 x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
