#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  vector<int> t(m);
  for (int i = 0; i < m; ++i) {
    cin >> t[i];
  }
  multiset<int> s(h.begin(), h.end());
  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    auto it = s.upper_bound(t[i]);
    if (it != s.begin()) {
      --it;
      ans.push_back(*it);
      s.erase(it);
    } else {
      ans.push_back(-1);
    }
  }
  for (int price : ans) {
    cout << price << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
