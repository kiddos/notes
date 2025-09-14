#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  // set<array<int,3>> s;
  // vector<array<int,2>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  // vector<vector<int>> next_dir = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  // s.insert({1, 0, 0});
  // s.insert({0, 1, 1});
  // s.insert({-1, 0, 2});
  // s.insert({0, -1, 3});
  // for (int k = 2; k <= n; ++k) {
  //   set<array<int,3>> s2;
  //   for (auto [r, c, d] : s) {
  //     for (int d2 : next_dir[d]) {
  //       int r2 = r + delta[d2][0], c2 = c + delta[d2][1];
  //       s2.insert({r2, c2, d2});
  //     }
  //   }
  //   s = std::move(s2);
  // }
  //
  // set<pair<int,int>> final;
  // for (auto [r, c, d] : s) {
  //   final.insert({r, c});
  // }
  // cout << final.size() << endl;

  // 1 2  3 4  5  6  7  8  9 10 11
  // 4 4 12 9 24 16 40 25 60 36 84
  // so look at the pattern
  // if n is even
  // the answer is (n/2+1) ^ 2
  // if n is odd
  // the answer is ((n+1)/2 + 1) * (n+1)/2 / 2 * 4
  i64 ans = 0;
  if (n % 2 == 0) {
    i64 x = n / 2 + 1;
    ans = x * x;
  } else {
    i64 x = (n+1) / 2;
    ans = x * (x+1) / 2 * 4;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
