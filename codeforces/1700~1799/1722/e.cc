#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;

  constexpr int MAX_SIZE = 1000;
  vector<vector<ll>> grid(MAX_SIZE+1, vector<ll>(MAX_SIZE+1));
  for (int i = 0; i < n; ++i) {
    ll w = 0, h = 0;
    cin >> w >> h;
    grid[w][h] += w * h;
  }

  vector<vector<ll>> dp(MAX_SIZE+1, vector<ll>(MAX_SIZE+1));
  for (int i = 1; i <= MAX_SIZE; ++i) {
    for (int j = 1; j <= MAX_SIZE; ++j) {
      dp[i][j] = dp[i-1][j] + dp[i][j-1] + grid[i][j] - dp[i-1][j-1];
    }
  }

  for (int i = 0; i < q; ++i) {
    int ws = 0, hs = 0, wb = 0, hb = 0;
    cin >> ws >> hs >> wb >> hb;
    ll total = dp[wb-1][hb-1] - dp[ws][hb-1] - dp[wb-1][hs]  + dp[ws][hs];
    cout << total << endl;
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
