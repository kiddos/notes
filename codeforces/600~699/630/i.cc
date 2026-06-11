#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 power(i64 x, int n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
    }
    n >>= 1;
    x = (x * x);
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  int parking_spot = 2 * n - 2;
  int left = parking_spot - n;

  auto count = [&](i64 x) -> i64 {
    if (x == 0) {
      return 1LL;
    }
    return 3LL * power(4LL, x-1);
  };

  i64 ans = 0;
  for (int l = 0; l <= left; ++l) {
    int r = left - l;
    ans += count(l) * count(r) * 4LL;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
