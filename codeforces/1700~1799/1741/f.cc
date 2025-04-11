#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_S = 1e9;

bool remove_duplicate_color(vector<pair<int,int>>& reach) {
  int n = reach.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (reach[i].second == reach[j].second) {
        reach.erase(reach.begin()+j);
        return true;
      }
    }
  }
  return false;
}

void solve(vector<array<int,4>>& segments, vector<int>& ans) {
  vector<array<int,5>> end_points;
  int n = segments.size();
  for (int i = 0; i < n; ++i) {
    auto [left, right, color, idx] = segments[i];
    end_points.push_back({left, right, color, idx, 0});
    end_points.push_back({right, left, color, idx, 1});
  }
  sort(end_points.begin(), end_points.end());

  for (int t = 0; t < 2; ++t) {
    vector<pair<int,int>> reach = {{-MAX_S, -1}, {-MAX_S, -1}};
    int m = end_points.size();
    for (int i = 0; i < m; ++i) {
      auto [x, y, color, idx, d] = end_points[i];
      if (d == 0) {
        reach.push_back({y, color});
        sort(reach.rbegin(), reach.rend());
        if (!remove_duplicate_color(reach)) {
          reach.pop_back();
        }
      } else {
        for (auto [f, c2] : reach) {
          if (c2 != color) {
            ans[idx] = min(ans[idx], max(y - f, 0));
          }
        }
      }
    }

    reverse(end_points.begin(), end_points.end());
    for (auto &[x, y, c, i, rd] : end_points) {
      x = MAX_S - x;
      y = MAX_S - y;
      rd ^= 1;
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int,4>> segments;
  vector<array<int,4>> rev_segments;
  for (int i = 0; i < n; ++i) {
    array<int,4> a;
    for (int j = 0; j < 3; ++j) {
      cin >> a[j];
    }
    a[3] = i;
    segments.push_back(a);
  }

  vector<int> ans(n, numeric_limits<int>::max());
  solve(segments, ans);

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
