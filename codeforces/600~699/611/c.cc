#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int h = 0, w = 0;
  cin >> h >> w;
  vector<string> s(h);
  for (int r = 0; r < h; ++r) {
    cin >> s[r];
  }

  int q = 0;
  cin >> q;
  vector<array<int,4>> queries;
  for (int i = 0; i < q; ++i) {
    array<int,4> a;
    for (int j = 0; j < 4; ++j) {
      cin >> a[j];
      a[j]--;
    }
    queries.push_back(a);
  }

  vector<vector<int>> right(h, vector<int>(w));
  vector<vector<int>> bot(h, vector<int>(w));
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (s[r][c] == '.') {
        if (r > 0 && s[r-1][c] == '.') {
          bot[r][c]++;
        }
        if (c > 0 && s[r][c-1] == '.') {
          right[r][c]++;
        }
      }
    }
  }
  vector<vector<int>> p1(h+1, vector<int>(w+1));
  vector<vector<int>> p2(h+1, vector<int>(w+1));
  for (int r = 1; r <= h; ++r) {
    for (int c = 1; c <= w; ++c) {
      p1[r][c] = p1[r-1][c] + p1[r][c-1] + right[r-1][c-1] - p1[r-1][c-1];
      p2[r][c] = p2[r-1][c] + p2[r][c-1] + bot[r-1][c-1] - p2[r-1][c-1];
    }
  }

  auto range_query = [&](vector<vector<int>>& p, int r1, int c1, int r2, int c2) -> int {
    if (r1 > r2 || c1 > c2) {
      return 0;
    }
    return p[r2+1][c2+1] - p[r1][c2+1] - p[r2+1][c1] + p[r1][c1];
  };

  vector<i64> ans;
  for (auto [r1, c1, r2, c2] : queries) {
    i64 right_sum = range_query(p1, r1, c1+1, r2, c2);
    i64 bot_sum = range_query(p2, r1+1, c1, r2, c2);
    ans.push_back(right_sum + bot_sum);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
