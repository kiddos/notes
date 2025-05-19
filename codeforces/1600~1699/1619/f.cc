#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  int at_least = n / m;
  int more = n - at_least * m;

  set<pair<int,int>> s;
  for (int i = 1; i <= n; ++i) {
    s.insert({0, i});
  }

  vector<vector<vector<int>>> ans;
  for (int j = 0; j < k; ++j) {
    set<pair<int,int>> s2;
    vector<vector<int>> result(m);
    for (int i = 0; i < more; ++i) {
      for (int c = 0; c <= at_least; ++c) {
        auto [count, idx] = *s.begin();
        s.erase(s.begin());
        result[i].push_back(idx);
        s2.insert({count+1, idx});
      }
    }
    for (int i = more; i < m; ++i) {
      for (int c = 0; c < at_least; ++c) {
        auto [count, idx] = *s.begin();
        s.erase(s.begin());
        result[i].push_back(idx);
        s2.insert({count, idx});
      }
    }
    s = std::move(s2);

    // assert(s.rbegin()->first - s.begin()->first <= 1);

    ans.push_back(result);
  }

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j].size() << " ";
      for (int idx : ans[i][j]) {
        cout << idx << " ";
      }
      cout << endl;
    }
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
