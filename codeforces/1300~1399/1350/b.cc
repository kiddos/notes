#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_factors(int x) {
  vector<int> factors;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      factors.push_back(i);
      if (i * i != x) {
        factors.push_back(x / i);
      }
    }
  }
  return factors;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> s(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  vector<int> dp(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    vector<int> factors = get_factors(i);
    for (int f : factors) {
      if (s[i] > s[f]) {
        dp[i] = max(dp[i], dp[f]+1);
      }
    }
  }
  int ans = *max_element(dp.begin(), dp.end());
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
