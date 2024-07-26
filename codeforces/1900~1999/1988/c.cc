#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  vector<i64> bits;
  for (int b = 62; b >= 0; --b) {
    if (n & (1LL<<b)) {
      bits.push_back(1LL << b);
    }
  }

  vector<i64> ans;
  for (int i = 0; i < (int)bits.size(); ++i) {
    if (n ^ bits[i]) {
      ans.push_back(n ^ bits[i]);
    }
  }
  ans.push_back(n);
  
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); ++i) {
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
