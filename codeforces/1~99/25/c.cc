#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<i64>> d(n, vector<i64>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> d[i][j];
    }
  }
  vector<vector<i64>> dp = d;
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  i64 total = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      total += dp[i][j];
    }
  }

  auto update = [&](i64& current, i64 new_val, i64& decrease) {
    if (new_val < current) {
      decrease += current - new_val;
      current = new_val;
    }
  };

  int k = 0;
  cin >> k;
  vector<i64> ans;
  for (int t = 0; t < k; ++t) {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    a--;
    b--;
    if (c < dp[a][b]) {
      i64 decrease = 0;
      update(dp[a][b], c, decrease);
      update(dp[b][a], c, decrease);
      for (int node : {a, b}) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            update(dp[i][j], dp[i][node] + dp[node][j], decrease);
          }
        }
      }
      total -= decrease / 2;
    }
    ans.push_back(total);
  }

  for (int i = 0; i < k; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
