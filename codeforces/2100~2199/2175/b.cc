#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  // fastest way to generate an array with all subarray xor != 0
  // is let p[i] = i
  // a[i] = p[i-1] ^ p[i]
  // this works because when xor a[i] ~ a[j],
  // the result will be p[i-1] ^ p[i] ^ p[i] ^ p[i+1] ^ ... ^ p[j-1] ^ p[j]
  // which is p[i-1] ^ p[j]

  int n = 0, l = 0, r = 0;
  cin >> n >> l >> r;
  vector<int> p(n+1);
  iota(p.begin(), p.end(), 0);
  p[r] = l-1;
  vector<int> ans(n+1);
  for (int i = 1; i <= n; ++i) {
    ans[i] = p[i-1] ^ p[i];
  }

  for (int i = 1; i <= n; ++i) {
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
