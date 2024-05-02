#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> ans;
  int msb = 31 - __builtin_clz(k);
  for (int b = 0; (1<<b) <= n; ++b) {
    if (b == msb) continue;
    ans.push_back(1 << b);
  }
  ans.push_back(k ^ (1<< msb));
  ans.push_back(k+1);
  ans.push_back(k + 1 + (1<<msb));

  cout << ans.size() << endl;
  for (int x : ans) cout << x << " ";
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
