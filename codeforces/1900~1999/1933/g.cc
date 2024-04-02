#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 1001
// 0110
// 1001
// 0110
//
// 0011
// 1100
// 0011
// 1100
//
// 1010
// 1010
// 0101
// 0101
//
// 1010
// 0101
// 0101
// 1010

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;

  vector<array<int,3>> queries;
  for (int i = 0; i < q; ++i) {
    int r = 0, c = 0;
    string shape;
    cin >> r >> c >> shape;

    queries.push_back({r, c, shape == "circle"});
  }

  cout << "8" << endl;
  vector<int> is_circle = {1, 1, 1, 1, 1, 1, 1, 1};
  for (auto& [r, c, circle] : queries) {
    if ((r + (c+1) / 2) % 2 == 1) {
      is_circle[0] &= circle;
      is_circle[1] &= (1-circle);
    } else {
      is_circle[1] &= circle;
      is_circle[0] &= (1-circle);
    }
    if ((r + c / 2) % 2 == 1) {
      is_circle[2] &= circle;
      is_circle[3] &= (1-circle);
    } else {
      is_circle[3] &= circle;
      is_circle[2] &= (1-circle);
    }

    if ((c + (r+1) / 2) % 2 == 1) {
      is_circle[4] &= circle;
      is_circle[5] &= (1-circle);
    } else {
      is_circle[5] &= circle;
      is_circle[4] &= (1-circle);
    }
    if ((c + r / 2) % 2 == 1) {
      is_circle[6] &= circle;
      is_circle[7] &= (1-circle);
    } else {
      is_circle[7] &= circle;
      is_circle[6] &= (1-circle);
    }

    int ans = accumulate(is_circle.begin(), is_circle.end(), 0);
    cout << ans << endl;
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
