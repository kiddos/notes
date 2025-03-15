#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int h = 0, w = 0;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; ++i) {
    cin >> s[i];
  }

  pair<int,int> p = {0, 0};
  int ans = s[0][0] == '*' ? 1 : 0;
  while (true) {
    int dist = numeric_limits<int>::max();
    pair<int,int> p2 = p;
    for (int r = p.first; r < h; ++r) {
      for (int c = p.second; c < w; ++c) {
        if (r == p.first && c == p.second) {
          continue;
        }

        if (s[r][c] == '*') {
          int d = r-p.first + c - p.second;
          if (d < dist) {
            p2 = {r, c};
            dist = d;
          }
        }
      }
    }
    
    if (dist == numeric_limits<int>::max()) {
      break;
    }
    ans++;
    p = std::move(p2);
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
