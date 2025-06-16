#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << "0" << endl;
    return;
  }

  sort(a.rbegin(), a.rend());

  int g = a[0];
  for (int i = 1; i < n; ++i) {
    g = gcd(g, a[i]);
  }
  // cout << "g=" << g << endl;

  bool found = false;
  for (int i = 0; i < n; ++i) {
    if (a[i] == g) {
      found = true;
      break;
    }
  }

  int ans = n + n;
  if (found) {
    ans = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != g) {
        ans++;
      }
    }
    // cout << "here??" << endl;
    cout << ans << endl;
    return;
  }
  
  constexpr int inf = 100000000;
  int max_a = *max_element(a.begin(), a.end());
  vector<int> dp(max_a+1, inf);
  dp[a[0]] = 1;
  for (int i = 1; i < n; ++i) {
    vector<int> dp2 = dp;
    dp2[a[i]] = 1;
    for (int g1 = 1; g1 <= max_a; ++g1) {
      int g2 = gcd(g1, a[i]);
      dp2[g2] = min(dp2[g2], dp[g1]+1);
    }
    dp = std::move(dp2);

    if (dp[g] < inf) {
      int total = n - 1 + dp[g]-1;
      ans = min(ans, total);
    }
  }

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
