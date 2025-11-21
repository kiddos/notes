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
  string x;
  cin >> x;
  int i1 = min_element(p.begin(), p.end()) - p.begin();
  int in = max_element(p.begin(), p.end()) - p.begin();
  if (x[0] == '1' || x.back() == '1' || x[i1] == '1' || x[in] == '1') {
    cout << "-1" << endl;
    return;
  }
  vector<pair<int,int>> ans;
  ans.push_back({1, i1+1});
  ans.push_back({1, in+1});
  ans.push_back({in+1, n});
  ans.push_back({i1+1, n});
  ans.push_back({1, n});

  cout << ans.size() << endl;
  for (auto [l, r] : ans) {
    cout << l << " " << r << endl;
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
