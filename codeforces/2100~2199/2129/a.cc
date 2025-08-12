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
  map<int, vector<pair<int,int>>> endings;
  for (int i = 0; i < n; ++i) {
    endings[a[i]].push_back({b[i], i});
  }
  vector<int> ans;
  for (auto [l, rs] : endings) {
    sort(rs.rbegin(), rs.rend());
    ans.push_back(rs[0].second + 1);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int idx : ans) {
    cout << idx << " ";
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
