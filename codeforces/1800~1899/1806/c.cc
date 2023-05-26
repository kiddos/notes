#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  int m = 2 * n;
  vector<int> p(m);
  for (int i = 0; i < m; ++i) cin >> p[i];


  ll sum = 0;
  ll ans = 0;
  for (int i = 0; i < m; ++i) {
    sum += abs(p[i] - (-1));
    ans += abs(p[i]);
  }

  if (n == 1) {
    ll s = 0;
    for (int i = 0; i < m; ++i) {
      s += abs(p[i] - p[0]);
    }
    ans = min(ans, s);
  }

  if (n == 2) {
    ll s = 0;
    for (int i = 0; i < 4; ++i) s += abs(p[i] - 2);
    ans = min(ans, s);
  }

  if (n % 2 == 0) {
    for (int i= 0; i < m; ++i) {
      ans = min(ans, sum - abs(p[i] - (-1)) + abs(p[i] - n));
    }
  }
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
