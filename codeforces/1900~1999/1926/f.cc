#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<string> grid(7);
  for (int i = 0; i < 7; ++i) cin >> grid[i];

  auto is_x = [&](int r, int c) -> bool {
    if (r < 0 || r >= 5 || c < 0 || c >= 5) return false;
    return grid[r][c] == 'B' && grid[r+1][c+1] == 'B' && grid[r+2][c+2] == 'B' && grid[r][c+2] == 'B' && grid[r+2][c] == 'B';
  };

  auto has_x = [&](int offset) -> bool {
    for (int r = 0; r < 5; ++r) {
      int c0 = r % 2 == 0 ? offset : 1-offset;
      for (int c = c0; c < 5; c += 2) {
        if (is_x(r, c)) return true;
      }
    }
    return false;
  };

  set<pair<int,int>> s;
  for (int r = 0; r < 5; ++r) {
    for (int c = 0; c < 5; ++c) {
      if (is_x(r, c)) {
        s.insert({r, c});
        s.insert({r+1, c+1});
        s.insert({r+2, c+2});
        s.insert({r+2, c});
        s.insert({r, c+2});
      }
    }
  }
  vector<pair<int,int>> coords(s.begin(), s.end());
  vector<pair<int,int>> even, odd;
  for (int i = 0; i < (int)coords.size(); ++i) {
    int r = coords[i].first, c = coords[i].second;
    if ((r+c) % 2 == 0) {
      even.push_back(coords[i]);
    } else {
      odd.push_back(coords[i]);
    }
  }

  function<bool(vector<pair<int,int>>&, int, int, int)> backtrack = [&](vector<pair<int,int>>& coords, int idx, int ops, int offset) -> bool {
    if (ops == 0) {
      return !has_x(offset);
    }
    if (idx == (int) coords.size()) return 0;

    bool done = false;
    done = done || backtrack(coords, idx+1, ops, offset);
    int r = coords[idx].first, c = coords[idx].second;
    grid[r][c] = 'W';
    done = done || backtrack(coords, idx+1, ops-1, offset);
    grid[r][c] = 'B';
    return done;
  };

  int ans = 0;
  for (int even_op = 0; even_op <= 4; ++even_op) {
    if (backtrack(even, 0, even_op, 0)) {
      ans += even_op;
      break;
    }
  }
  for (int odd_op = 0; odd_op <= 4; ++odd_op) {
    if (backtrack(odd, 0, odd_op, 1)) {
      ans += odd_op;
      break;
    }
  }

  std::cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}