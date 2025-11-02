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

  auto found_diag1 = [&](int r, int c) -> bool {
    return (s[r-1][c-1] == 'M' && s[r+1][c+1] == 'S') ||
      (s[r+1][c+1] == 'M' && s[r-1][c-1] == 'S');
  };

  auto found_diag2 = [&](int r, int c) -> bool {
    return (s[r-1][c+1] == 'M' && s[r+1][c-1] == 'S') ||
      (s[r+1][c-1] == 'M' && s[r-1][c+1] == 'S');
  };

  auto found = [&](int i, int j) -> bool {
    return found_diag1(i, j) && found_diag2(i, j);
  };

  int ans = 0;
  for (int i = 1; i+1 < n; ++i) {
    for (int j = 1; j+1 < m; ++j) {
      if (s[i][j] == 'A') {
        if (found(i, j)) {
          ans++;
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
