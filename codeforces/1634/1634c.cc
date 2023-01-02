#include <bits/stdc++.h>

using namespace std;

bool solve(vector<vector<int>>& grid) {
  int n = grid.size(), k = grid[0].size();
  int max_price = n * k;
  int odd_price = 1, even_price = 2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      if (i % 2 == 0) {
        if (odd_price > max_price) return false;
        grid[i][j] = odd_price;
        odd_price += 2;
      } else {
        if (even_price > max_price) return false;
        grid[i][j] = even_price;
        even_price += 2;
      }
    }
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(k));
    bool ans = solve(grid);
    if (ans) {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
          cout << grid[i][j] << ' ';
        }
        cout << '\n';
      }
    } else {
      cout << "NO\n";
    }
  }
  cout << flush;
  return 0;
}
