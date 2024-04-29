#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_K = 60;
constexpr int NUM_COLORS = 6;
constexpr int MOD = 1e9 + 7;

vector<vector<int>> memo(MAX_K+1, vector<int>(NUM_COLORS));

// white  - 0
// yello  - 1
// green  - 2
// blue   - 3
// red    - 4
// orange - 5
vector<vector<int>> colors = {
  {2, 3, 4, 5},
  {2, 3, 4, 5},
  {0, 1, 4, 5},
  {0, 1, 4, 5},
  {0, 1, 2, 3},
  {0, 1, 2, 3},
};

i64 dp(int size, int color) {
  if (size == 1) {
    return 1;
  }
  if (memo[size][color]) {
    return memo[size][color];
  }
  i64 ans = 0;
  for (int c1 : colors[color]) {
    for (int c2 : colors[color]) {
      ans += (dp(size-1, c1) * dp(size-1, c2)) % MOD;
      ans %= MOD;
    }
  }
  return memo[size][color] = ans;
};


void solve() {
  int k = 0;
  cin >> k;
  i64 ans = 0;
  for (int c = 0; c < NUM_COLORS; ++c) {
    ans += dp(k, c);
    ans %= MOD;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
