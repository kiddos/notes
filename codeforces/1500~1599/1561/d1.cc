#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// f(n) = f(n-1) + f(n-2) + ... + f(1)
//        + f(n/2) + f(n/3) + f(n/4) + f(1)

void solve() {
  int n = 0, mod = 0;
  cin >> n >> mod;
  vector<i64> f(n+1);
  f[1] = 1;
  i64 sum = 1;
  for (int i = 2; i <= n; ++i) {
    f[i] = sum;

    for (int z = 2; z <= i;) {
      int z2 = i / (i / z);
      f[i] += (f[i / z] * (z2 - z + 1)) % mod;
      f[i] %= mod;
      z = z2 + 1;
    }

    sum += f[i];
    sum %= mod;
  }

  cout << f[n] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
