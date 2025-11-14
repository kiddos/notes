#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void cover(vector<vector<bool>>& grid, int diag, function<int(int,int)> get_diag) {
  int n = grid.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int d = get_diag(i, j);
      if (d == diag) {
        grid[i][j] = true;
      }
    }
  }
}

bool check_covered(int n, vector<pair<int,int>>& coords, int diag1, int diag2, function<int(int,int)> get_diag) {
  vector<vector<bool>> grid(n, vector<bool>(n));
  cover(grid, diag1, get_diag);
  cover(grid, diag2, get_diag);

  for (auto [r, c] : coords) {
    if (!grid[r][c]) {
      return false;
    }
  }
  return true;
}

bool is_square(vector<pair<int,int>>& coords) {
  if (coords.size() != 4) {
    return false;
  }
  return coords[0].first == coords[1].first &&
    coords[0].second+1 == coords[1].second &&
    coords[0].first+1 == coords[2].first &&
    coords[0].second == coords[2].second &&
    coords[0].first+1 == coords[3].first &&
    coords[0].second+1 == coords[3].second;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  // if there is a black cell,
  // 2 adjacent diagnal should cover all black cells,
  // since it cannot turn
  vector<pair<int,int>> coords;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == '#') {
        coords.push_back({i, j});
      }
    }
  }

  if (coords.size() == 0) {
    cout << "YES" << endl;
    return;
  }

  auto get_diag1 = [](int r, int c) {
    return r - c;
  };
  int diag1 = get_diag1(coords[0].first, coords[0].second);
  auto get_diag2 = [](int r, int c) {
    return r + c;
  };
  int diag2 = get_diag2(coords[0].first, coords[0].second);
  if (check_covered(n, coords, diag1, diag1+1, get_diag1) || 
      check_covered(n, coords, diag1, diag1-1, get_diag1) ||
      check_covered(n, coords, diag2, diag2+1, get_diag2) ||
      check_covered(n, coords, diag2, diag2-1, get_diag2) ||
      is_square(coords)) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
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
