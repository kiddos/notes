#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


constexpr int MOD = 1000000007;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  if (k == 1) {
    cout << (n % MOD) << endl;
    return;
  }

  vector<i64> fib = {1 % k, 1 % k};
  while (fib.back() != 0) {
    int n = fib.size();
    fib.push_back((fib[n-1] + fib[n-2]) % k);
  }
  i64 first = fib.size();
  i64 ans = first % MOD;
  ans *= (n % MOD);
  ans %= MOD;
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
