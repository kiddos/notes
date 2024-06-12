#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 lcm(i64 x, i64 y) {
  i64 g = gcd(x, y);
  return x * y / g;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> k(n);
  for (int i = 0; i < n; ++i) cin >> k[i];
  i64 l = 1;
  for (int i = 0; i < n; ++i) {
    l = lcm(l, k[i]);
  }
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = l / k[i];
  }
  i64 sum = accumulate(ans.begin(), ans.end(), 0LL);
  if (sum >= l) {
    cout << "-1" << endl;
    return;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
