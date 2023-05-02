#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<int>& x, int n) {
  const int MOD = 1e9 + 7;
  int all_or = 0;
  for (int i = 0; i < x.size(); ++i) all_or = all_or | x[i];
  ll ans = all_or % MOD;
  for (int i = 0; i < n-1; ++i) {
    ans *= 2;
    ans %= MOD;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; ++i) {
      int l = 0, r = 0;
      cin >> l >> r >> x[i];
    }
    ll ans = solve(x, n);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
