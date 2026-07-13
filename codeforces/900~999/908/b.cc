#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }
  string s;
  cin >> s;

  array<int,2> start, end;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'S') {
        start = {i, j};
      } else if (grid[i][j] == 'E') {
        end = {i, j};
      }
    }
  }

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  auto possible = [&](vector<int>& ordering) -> bool {
    array<int,2> current = start;
    for (char ch : s) {
      vector<int>& d = delta[ordering[ch-'0']];
      for (int di = 0; di < 2; ++di) {
        current[di] += d[di];
      }
      if (current[0] < 0 || current[0] >= n || current[1] < 0 || current[1] >= m) {
        return false;
      }
      if (grid[current[0]][current[1]] == '#') {
        return false;
      }
      if (grid[current[0]][current[1]] == 'E') {
        return true;
      }
    }
    return false;
  };

  vector<int> order = {0, 1, 2, 3};
  int ans = 0;
  do {
    if (possible(order)) {
      ans++;
    }
  } while (next_permutation(order.begin(), order.end()));

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
