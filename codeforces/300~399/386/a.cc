#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({a[i], i});
  }
  sort(p.rbegin(), p.rend());
  cout << p[0].second+1 << " " << p[1].first << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
