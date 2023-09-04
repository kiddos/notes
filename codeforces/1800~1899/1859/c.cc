#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  
  i64 ans = 0;
  for (int i = n-1; i >= 0; --i) {
    vector<int> p2 = p;
    reverse(p2.begin() + i, p2.end());

    i64 cost = 0;
    i64 max_val = 0;
    for (int j = 0; j < n; ++j) {
      max_val = max(max_val, (i64)(j+1) * p2[j]);
      cost += (j+1) * p2[j];
    }
    cost -= max_val;
    ans = max(ans, cost);
  }
  cout << ans << endl;
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
