#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> counts(2);
  for (int i = 0; i < n; ++i) {
    counts[abs(a[i])%2]++;
  }

  int memo[101][101][2][2];
  memset(memo, -1, sizeof(memo));

  function<bool(int,int,int,int)> dp = [&](int even, int odd, int p, int t) -> bool {
    if (even == 0 && odd == 0) {
      return t == 0 ? p % 2 == 0 : p % 2 == 1;
    }
    if (memo[even][odd][p][t] >= 0) {
      return memo[even][odd][p][t];
    }

    bool ans = true;
    if (t == 0)  {
      if (even) {
        ans = ans && dp(even-1, odd, p, t^1);
      }
      if (odd) {
        ans = ans && dp(even, odd-1, p^1, t^1);
      }
    } else {
      if (even) {
        ans = ans && dp(even-1, odd, p, t^1);
      }
      if (odd) {
        ans = ans && dp(even, odd-1, p, t^1);
      }
    }
    return memo[even][odd][p][t] = !ans;
  };

  bool ans = dp(counts[0], counts[1], 0, 0);
  if (ans) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
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
