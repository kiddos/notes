#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 m = 0;
  cin >> n >> m;
  vector<i64> f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= m;
  }

  vector<i64> prefix(n+1);
  for (int c = 1; c <= n; ++c) {
    i64 p = f[c] * f[n-c];
    p %= m;
    p *= (n-c+1);
    p %= m;
    prefix[c] = p;
  }

  for (int c = 1; c <= n; ++c) {
    prefix[c] += prefix[c-1];
    prefix[c] %= m;
  }

  i64 ans = 0;
  for (int i = n; i >= 1; --i) {
    ans += f[n-1] * n;
    ans %= m;
    i64 p = prefix[i] - prefix[1];
    p %= m;
    p += m;
    p %= m;
    ans += p;
    ans %= m;
    // for (int j = i-1; j >= 1; --j) {
    //   int c = i-j+1;
    //   i64 result = f[c] * f[n-c] * (n-c+1);
    //   ans += f[c] * f[n-c] * (n-c+1);
    // }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
