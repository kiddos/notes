#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<array<int,3>> ans;
  auto swap = [&](int i1, int i2) {
    for (int k = 0; k < 3; ++k) {
      ans.push_back({1, i1, i2});
      ans.push_back({2, i1, i2});
    }
  };

  for (int i = 1; i <= n; i += 2) {
    swap(i, i+1);
  }

  cout << ans.size() << endl;
  for (auto [type, i, j] : ans) {
    cout << type << " " << i << " " << j << endl;
  }
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
