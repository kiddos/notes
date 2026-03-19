#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  constexpr int inf = 1e9;
  map<int,int> memo;
  auto dfs = [&](const auto& self, int i) -> int {
    if (i == k) {
      return 0;
    }
    if (i < k) {
      return inf;
    }
    if (memo.count(i)) {
      return memo[i];
    }
    int i1 = i / 2;
    int i2 = (i+1) / 2;
    int ans = inf;
    ans = min(ans, self(self, i1) + 1);
    ans = min(ans, self(self, i2) + 1);
    return memo[i] = ans;
  };
  
  int ans = dfs(dfs, n);
  if (ans < inf) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
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
