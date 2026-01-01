#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<bool> dp(n+1);
  vector<int> prev(n+1);
  dp[0] = true;
  vector<int> rooms = {3, 5, 7};
  for (int i = 0; i < n; ++i) {
    if (dp[i]) {
      for (int r : rooms) {
        if (i+r <= n) {
          dp[i+r] = true;
          prev[i+r] = i;
        }
      }
    }
  }

  if (!dp[n]) {
    cout << "-1" << endl;
    return;
  }
  vector<int> count(3);
  int x = n;
  while (x > 0) {
    int x2 = prev[x];
    int added = x - x2;
    if (added == 3) {
      count[0]++;
    } else if (added == 5) {
      count[1]++;
    } else if (added == 7) {
      count[2]++;
    }
    x = x2;
  }
  cout << count[0] << " " << count[1] << " " << count[2] << endl;
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
