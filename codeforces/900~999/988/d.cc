#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());

  set<i64> s(x.begin(), x.end());

  vector<i64> ans = {x[0]};
  for (int i = 0; i < n; ++i) {
    vector<i64> possible = {};
    for (int d1 = 0; d1 <= 32; ++d1) {
      i64 p2 = 1LL << d1;
      if (s.count(x[i] + p2)) {
        possible = {x[i], x[i] + p2};
        if (s.count(x[i] + p2 * 2)) {
          possible.push_back(x[i] + p2 * 2);
        }
      }
      if (possible.size() > ans.size()) {
        ans = possible;
      }
    }
  }

  int m = ans.size();
  cout << m << endl;
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
