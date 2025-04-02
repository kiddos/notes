#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 l = 0, r = 0;
  cin >> n >> l >> r;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  // prefix xor
  vector<int> p = a;
  for (int i = 1; i <= n; ++i) {
    p[i] ^= p[i-1];
  }
  if (n % 2 == 0) {
    a.push_back(p[n/2]);
    p.push_back(p.back() ^ a.back());
    n++;
  }

  function<int(i64)> g = [&](i64 i) -> int {
    if (i <= n) {
      return p[i];
    }
    if (i % 2 == 1 && i > 2 * n) {
      // since a[m*2] = a[m*2+1] = a[m]
      return p[n];
    } else {
      return g(i-1) ^ g(i/2);
    }
  };

  // vector<int> x = a;
  // for (int i = n+1; i <= l; ++i) {
  //   x.push_back(p[i/2]);
  //   p.push_back(p.back() ^ x.back());
  // }
  // 
  // cout << "a=";
  // for (int i = 1; i <= l; ++i) {
  //   cout << x[i] << " ";
  // }
  // cout << endl;
  // cout << "p=";
  // for (int i = 1; i <= l; ++i) {
  //   cout << p[i] << " ";
  // }
  // cout << endl;
  // cout << "g=";
  // for (int i = 1; i <= l; ++i) {
  //   cout << g(i) << " ";
  // }
  // cout << endl;
  //
  // cout << "g(r)=" << g(r) << endl;
  // cout << "g(l)=" << g(l-1) << endl;

  int ans = g(r) ^ g(l-1);
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
