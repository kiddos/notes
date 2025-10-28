#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int,3>> interval;
  for (int i = 0; i < n; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    interval.push_back({x, y, i});
  }
  sort(interval.begin(), interval.end(), [&](auto& i1, auto& i2) {
    if (i1[1] == i2[1]) {
      return i1[0] > i2[0];
    }
    return i1[1] < i2[1];
  });

  vector<bool> ans1(n);
  set<pair<int,int>> starts;
  for (int i = 0; i < n; ++i) {
    auto [x, y, idx] = interval[i];
    auto it = starts.lower_bound({x, -1});
    if (it != starts.end()) {
      ans1[idx] = true;
    }
    starts.insert({x, idx});
  }
  starts.clear();

  vector<bool> ans2(n);
  for (int i = 0; i < n; ++i) {
    auto [x, y, idx] = interval[i];
    auto it = starts.lower_bound({x, -1});
    while (it != starts.end()) {
      ans2[it->second] = true;
      it = starts.erase(it);
    }
    starts.insert({x, idx});
  }

  for (int i = 0; i < n; ++i) {
    cout << ans1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans2[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
