#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int max_val = *max_element(a.begin(), a.end());
  vector<int> counts(max_val+1);
  for (int i = 0; i < n; ++i) {
    counts[a[i]]++;
  }

  vector<i64> dp(max_val+1);
  for (int g = max_val; g >= 1; --g) {
    int x = g;
    i64 total = 0;
    while (x <= max_val) {
      total += counts[x];
      x += g;
    }
    dp[g] = total * (total - 1) / 2;
  }
  for (int g = max_val; g >= 1; --g) {
    for (int j = g+g; j <= max_val; j += g) {
      dp[g] -= dp[j];
    }
  }

  vector<int> u = a;
  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());
  vector<bool> cannot_use(max_val+1);
  for (int val : u) {
    for (int i = val; i <= max_val; i += val) {
      cannot_use[i] = true;
    }
  }

  i64 ans = 0;
  for (int g = 1; g <= max_val; ++g) if (!cannot_use[g]) {
    ans += dp[g];
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
