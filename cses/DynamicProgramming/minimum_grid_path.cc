#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<pair<int,int>> cells;
  cells.push_back({0, 0});
  string ans;
  while (!cells.empty()) {
    sort(cells.begin(), cells.end());
    cells.resize(unique(cells.begin(), cells.end()) - cells.begin());
    char ch = 'Z';
    for (auto [r, c] : cells) {
      ch = min(ch, s[r][c]);
    }
    ans.push_back(ch);
    vector<pair<int,int>> next_cells;
    for (auto [r, c] : cells) {
      if (s[r][c] == ch) {
        if (r+1 < n) {
          next_cells.push_back({r+1, c});
        }
        if (c+1 < n) {
          next_cells.push_back({r, c+1});
        }
      }
    }
    cells = std::move(next_cells);
  }
  cout << ans << endl;
}
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  solve();
  return 0;
}
