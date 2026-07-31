#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> f(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({f[i], i});
  }
  sort(p.begin(), p.end());
  i64 ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += abs(p[i-1].second - p[i].second);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
