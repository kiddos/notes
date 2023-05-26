#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll cost1 = 1e12;
constexpr ll cost2 = 1e12 + 1;

void solve() {
  string s;
  cin >> s;

  int n = s.length();

  vector<vector<pair<ll,int>>> memo(n, vector<pair<ll,int>>(2, {-1, 0}));
  function<pair<ll,int>(int,int)> dp = [&](int i, int end) {
    if (i == 0) {
      if (s[i] == '1' && end == 0) {
        return pair<ll,int>{cost2, 0};
      }
      return pair<ll, int>{0, s[i]-'0'};
    }
    if (memo[i][end].first >= 0) return memo[i][end];

    pair<ll, int> ans;
    if (s[i] == '0') {
      if (end == 0) {
        ans = dp(i-1, 0);
      } else {
        ans = dp(i-1, 1);
        ans.first += min(ans.second * cost1, cost2);
        ans = min(ans, dp(i-1, 0));
      }
    } else {
      if (end == 0) {
        ans = dp(i-1, 0);
        ans.first += cost2;
      } else {
        ans = min(dp(i-1, 0), dp(i-1, 1));
        ans.second++;
      }
    }
    return memo[i][end] = ans;
  };

  auto ans = min(dp(n-1, 0), dp(n-1, 1));
  cout << ans.first << endl;
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
