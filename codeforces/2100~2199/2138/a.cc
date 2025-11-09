#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0;
  i64 x = 0;
  cin >> k >> x;

  i64 m = 1LL << k;
  vector<int> ans;
  auto backtrack = [&](const auto& self, i64 x1) -> bool {
    i64 x2 = 2LL * m - x1;
    if (x1 == x2) {
      return true;
    }
    if (x2 > x1) {
      ans.push_back(1);
      if (self(self, x1 * 2)) {
        return true;
      }
      ans.pop_back();
    }

    if (x1 > x2) {
      ans.push_back(2);
      if (self(self, x1 - x2)) {
        return true;
      }
      ans.pop_back();
    }
    return false;
  };

  backtrack(backtrack, x);
  reverse(ans.begin(), ans.end());

  cout << ans.size() << endl;
  for (int o : ans) {
    cout << o << " ";
  }
  cout << endl;
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
