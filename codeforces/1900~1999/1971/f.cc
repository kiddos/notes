#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_R = 100000;

vector<int> ans(MAX_R+1, 1);

void solve() {
  i64 r = 0;
  cin >> r;

  int ans = 0;
  for (i64 x = 0, y = r; x <= r; ++x) {
    while (x * x + y * y >= (r+1) * (r+1)) {
      y--;
    }
    i64 h = y;
    while (x * x + h * h >= r * r && h > 0) {
      h--;
      ans++;
    }
  }
  ans *= 4;
  cout << ans << endl;
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
