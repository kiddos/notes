#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> w(n), h(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> h[i];
  }
  map<int,vector<int>> by_height, by_width;
  for (int i = 0; i < n; ++i) {
    by_height[h[i]].push_back(i);
    by_width[w[i]].push_back(i);
  }

  vector<int> ans(n, -1);
  set<pair<int,int>> added_w, added_h;
  auto it = by_width.begin();
  for (auto [height, indices] : by_height) {
    while (it != by_width.end() && it->first < height) {
      for (int j : it->second) {
        added_h.insert({h[j], j});
      }
      ++it;
    }

    for (int i : indices) {
      if (!added_w.empty()) {
        auto [wj, j] = *added_w.begin();
        if (wj < w[i]) {
          ans[i] = j+1;
        }
      }
      if (!added_h.empty()) {
        auto [hj, j] = *added_h.begin();
        if (hj < w[i]) {
          ans[i] = j+1;
        }
      }
    }

    for (int i : indices) {
      added_w.insert({w[i], i});
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
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
