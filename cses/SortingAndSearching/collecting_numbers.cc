#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n ; ++i) {
    cin >> x[i];
  }
  vector<pair<int,int>> p;
  for (int i = 0; i < n; ++i) {
    p.push_back({x[i], i});
  }
  sort(p.begin(), p.end());
  int last_idx = -1;
  int ans = 1;
  for (auto [pi, idx] : p) {
    if (idx < last_idx) {
      ans++;
    }
    last_idx = idx;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
