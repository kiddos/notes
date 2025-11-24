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
  i64 n = 0;
  cin >> n;
  i64 ans = 0;

  // observation 1:
  // if we have divisor d, it will contribute to the answer n / d times
  // so the answer is sum of d * (n / d) for d from 1 ~ n
  // observation 2:
  // when d > n / 2, the count is 1
  // when n / 3 < d <= n / 2 , the count is 2
  // when n / 4 < d <= n / 3, the count is 3
  i64 inv_2 = power(2, MOD-2);
  for (i64 d = 1; d <= n;) {
    i64 count = n / d;
    i64 l = d+1, r = n;
    i64 d2 = d;
    while (l <= r) {
      i64 mid = l + (r-l) / 2;
      i64 count2 = n / mid;
      if (count2 >= count) {
        l = mid+1;
        d2 = mid;
      } else {
        r = mid-1;
      }
    }
    i64 sum = (d2 + d) % MOD;
    sum *= (d2 - d + 1) % MOD;
    sum %= MOD;
    sum *= inv_2;
    sum %= MOD;
    sum *= count;
    sum %= MOD;

    ans += sum;
    ans %= MOD;
    d = d2 + 1;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
