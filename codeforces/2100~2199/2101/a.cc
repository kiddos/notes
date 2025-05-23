#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> ans(n, vector<int>(n));
  int mid = n/2;
  array<int,4> rect = {mid, mid, mid, mid};
  vector<int> delta = {-1, -1, 1, 1};

  auto cover = [&](int x1, int y1, int x2, int y2) -> i64 {
    i64 h = (x1+1) * (n-x2);
    i64 w = (y1+1) * (n-y2);
    return h * w;
  };

  int k = 1;
  while (true) {
    // 4 ways to do
    // 1. x1 -= 1
    // 2. y1 -= 1
    // 3. x2 += 1
    // 4. y2 += 1
    vector<pair<int,int>> possible;
    for (int d = 0; d < 4; ++d) {
      if  (rect[d] + delta[d] >= 0 && rect[d] + delta[d] < n) {
        array<int, 4> r = rect;
        r[d] += delta[d];
        i64 contribute = cover(r[0], r[1], r[2], r[3]);
        possible.push_back({contribute, d});
      }
    }
    if (possible.empty()) {
      break;
    }
    sort(possible.begin(), possible.end());

    int d = possible.back().second;
    rect[d] += delta[d];
    if (d % 2 == 0) {
      for (int r = rect[1]; r <= rect[3]; ++r) {
        ans[r][rect[d]] = k++;
      }
    } else {
      for (int c = rect[0]; c <= rect[2]; ++c) {
        ans[rect[d]][c] = k++;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
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
