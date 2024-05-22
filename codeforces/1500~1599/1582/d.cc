#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 lcm(i64 x, i64 y) {
  int g = gcd(x, y);
  return x * y / g;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  constexpr int MAX_VAL = 10000;

  vector<int> ans(n, 1);
  i64 sum = 0;
  for (int i = 0; i < n-1; ++i) {
    sum += a[i];
  }
  for (int i = n-2; i >= 0 && sum >= MAX_VAL; --i) {
    if (a[i] > 0) {
      sum -= a[i] * 2;
      ans[i] = -1;
    }
  }
  if (sum == 0) {
    sum += a[0];
    ans[0] += 1;
  }

  i64 x = sum;
  i64 y = a.back();
  i64 l = lcm(abs(x), abs(y));
  for (int i = 0; i < n-1; ++i) {
    ans[i] *= l / abs(x);
  }
  ans.back() *= l / abs(y);
  if (x * y > 0) {
    ans.back() *= -1;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
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
