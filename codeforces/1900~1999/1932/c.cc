#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  i64 x1 = 0, y1 = 0;
  i64 g = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}

i64 mod_inv(i64 b, i64 m) {
  i64 x = 0, y = 0;
  i64 g = gcd(b, m);
  extended_euclidean(b / g, m / g, x, y);
  return x % m;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  string s;
  cin >> s;

  int l = 0, r = n-1;
  vector<i64> vals;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      vals.push_back(a[l++]);
    } else if (s[i] == 'R') {
      vals.push_back(a[r--]);
    }
  }
  vector<i64> ans;
  for (int i = n-1; i >= 0; --i) {
    i64 val = vals[i] % m;
    if (!ans.empty()) {
      val *= ans.back();
      val %= m;
    }
    ans.push_back(val);
  }
  reverse(ans.begin(), ans.end());

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << endl;
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
