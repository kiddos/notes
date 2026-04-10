#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> prime_factors(int x) {
  vector<int> p;
  for (int d = 2; d * d <= x; ++d) {
    while (x % d == 0) {
      x /= d;
      p.push_back(d);
    }
  }
  if (x > 1) {
    p.push_back(x);
  }
  p.resize(unique(p.begin(), p.end()) - p.begin());
  return p;
}

void solve() {
  int n = 0;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    vector<int> p = prime_factors(i);
    if (p.size() == 2) {
      ans++;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
