#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<i64> lcms;

i64 gcd(i64 a, i64 b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

i64 lcm(i64 x, i64 y) {
  i64 g = gcd(x, y);
  return x * y / g;
}

void precompute() {
  lcms = {1};
  for (int i = 2; lcms.back() <= 2e9; ++i) {
    lcms.push_back(lcm(lcms.back(), i));
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int m = min(n, (int)lcms.size() - 1);
  for (int i = 1; i <= m; ++i) {
    if (a[i] % lcms[i] == 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
