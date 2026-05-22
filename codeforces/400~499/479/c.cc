#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({a[i],  b[i]});
  }
  sort(p.begin(), p.end());
  int day = min(p[0].first, p[0].second);
  for (int i = 1; i < n; ++i) {
    auto [ai, bi] = p[i];
    if (bi >= day) {
      day = bi;
    } else {
      day = ai;
    }
  }
  cout << day << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
