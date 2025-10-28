#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[x[i]]++;
  }
  constexpr int MOD = 1e9 + 7;
  i64 ans = 1;
  for (auto [xi, c] : count) {
    ans *= (c+1);
    ans %= MOD;
  }
  ans -= 1;
  ans = (ans + MOD) % MOD;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
