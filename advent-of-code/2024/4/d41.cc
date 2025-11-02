#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  ifstream input("./input.txt");

  stringstream buffer;
  buffer << input.rdbuf();
  string line;
  vector<string> s;
  while (getline(buffer, line)) {
    s.push_back(line);
  }

  int n = s.size();
  int m  = s[0].length();

  string target = "XMAS";
  auto found = [&](int i, int j, vector<int>& d) -> bool {
    int r = i, c = j;
    for (int k = 0; k < (int)target.length(); ++k, r += d[0], c += d[1]) {
      if (r < 0 || r >= n || c < 0 || c >= m) {
        return false;
      }
      if (s[r][c] != target[k]) {
        return false;
      }
    }
    return true;
  };

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0,-1},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'X') {
        for (vector<int> d : delta) {
          if (found(i, j, d)) {
            ans++;
          }
        }
      }
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
