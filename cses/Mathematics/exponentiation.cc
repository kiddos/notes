#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }

    n >>= 1;
    x = (x * x) % MOD;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    i64 ans = power(a, b);
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
