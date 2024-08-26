#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  constexpr int INF = 1000000000;
  vector<int> dp(k+1, INF);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    int x = min(a[i], b[i]);
    int y = max(a[i], b[i]);
    int size = x + y + 1;
    vector<int> ops(size);
    int side1 = x, side2 = y;
    int j = 1;
    while (j < size) {
      if (side2 >= side1) {
        ops[j++] = side1 + ops[j-1];
        side2--;
      } else {
        ops[j++] = side2 + ops[j-1];
        side1--;
      }
    }

    // for (int j = 0; j < (int)ops.size(); ++j) {
    //   cout << ops[j] << " ";
    // }
    // cout << endl;

    for (int t = k; t >= 0; --t) {
      if (dp[t] < INF) {
        for (int j = 1; j < size && j + t <= k; ++j) {
          dp[t + j] = min(dp[t + j], dp[t] + ops[j]);
        }
      }
    }
  }

  if (dp[k] >= INF) {
    cout << "-1" << endl;
  } else {
    cout << dp[k] << endl;
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
