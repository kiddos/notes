#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  unordered_map<i64, int> factors;
  i64 x = n;
  for (i64 d = 2; d*d <= n; ++d) {
    while (x % d == 0) {
      factors[d]++;
      x /= d;
    }
  }
  if (x > 1) {
    factors[x]++;
  }
  i64 prime = 0;
  int len = 0;
  for (auto [f, c] : factors) {
    if (c > len) {
      prime = f;
      len = c;
    }
  }
  x = n;
  vector<i64> ans;
  while (x % (prime * prime) == 0) {
    ans.push_back(prime);
    x /= prime;
  }
  if (x > 1) {
    ans.push_back(x);
  }

  cout << ans.size() << endl;
  for (i64 f : ans) {
    cout << f << " ";
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
