#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> intervals;
  for (int i = 0; i < m; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    intervals.emplace_back(l, r);
  }

  vector<vector<int>> enter(n+1);
  vector<vector<int>> leave(n+1);
  for (int i = 0; i < m; ++i) {
    auto& [l, r] = intervals[i];
    enter[r].push_back(i);
    leave[l-1].push_back(i);
  }

  set<int> cats;
  multiset<int> ends;
  vector<int> dp(n+2);
  for (int i = n; i >= 0; --i) {
    while (!enter[i].empty()) {
      int cat = enter[i].back();
      cats.insert(cat);
      enter[i].pop_back();
      ends.insert(intervals[cat].second);
    }
    while (!leave[i].empty()) {
      int cat = leave[i].back();
      cats.erase(cat);
      leave[i].pop_back();
      ends.erase(ends.find(intervals[cat].second));
    }
    if (!ends.empty()) {
      dp[i] = (int)cats.size() + dp[(*ends.rbegin())+1];
    }
    dp[i] = max(dp[i], dp[i+1]);
  }

  int ans = *max_element(dp.begin(), dp.end());
  cout << ans << endl;
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
