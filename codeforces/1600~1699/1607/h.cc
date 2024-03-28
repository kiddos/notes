#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string empty;
  getline(cin, empty);

  int n = 0;
  cin >> n;
  vector<int> a(n), b(n), m(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> m[i];
  }
  
  map<i64, vector<array<int,4>>> groups;
  for (int i = 0; i < n; ++i) {
    i64 sum = (i64)a[i] + b[i] - m[i];
    groups[sum].push_back({a[i], b[i], m[i], i});
  }

  vector<int> x(n), y(n);
  for (auto group : groups) {
    vector<array<int, 4>>& g = group.second;
    int size = g.size();
    vector<pair<int,int>> intervals;
    for (int i = 0; i < size; ++i) {
      intervals.emplace_back(max(g[i][0] - g[i][2], 0), g[i][0]);
    }
    sort(intervals.begin(), intervals.end());

    vector<pair<int,int>> merged;
    for (int i = 0; i < size; ++i) {
      if (merged.empty() || intervals[i].first > merged.back().second) {
        merged.push_back(intervals[i]);
      } else {
        merged.back().first = max(merged.back().first, intervals[i].first);
        merged.back().second = min(merged.back().second, intervals[i].second);
      }
    }

    for (int i = 0; i < size; ++i) {
      int min_a = max(g[i][0] - g[i][2], 0);
      pair<int,int> a_range = {min_a, min_a};
      auto it = lower_bound(merged.begin(), merged.end(), a_range);
      int idx = g[i][3];
      x[idx] = g[i][0] - it->first;
      y[idx] = g[i][2] - x[idx];
    }
  }

  set<pair<int,int>> s;
  for (int i = 0; i < n; ++i) {
    pair<int,int> p = {a[i] - x[i], b[i] - y[i]};
    s.insert(p);
  }

  cout << s.size() << endl;
  for (int i = 0; i < n; ++i) {
    cout << x[i] << " " << y[i] << endl;
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
