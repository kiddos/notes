#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<int> prefix = p, suffix = p;
  for (int i = 1; i < n; ++i) {
    prefix[i] = gcd(prefix[i-1], prefix[i]);
  }
  for (int i = n-2; i >= 0; --i) {
    suffix[i] = gcd(suffix[i], suffix[i+1]);
  }
  i64 ans = prefix.back();
  for (int i = 1; i < n-1; ++i) {
    int min_connect = min(prefix[i], suffix[i]);
    ans += min_connect;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
