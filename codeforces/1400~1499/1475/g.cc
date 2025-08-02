#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;

vector<int> get_factors(int x) {
  vector<int> f;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      f.push_back(i);
      if (i * i != x) {
        f.push_back(x / i);
      }
    }
  }
  sort(f.begin(), f.end());
  return f;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> count(MAX_N+1);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  sort(a.begin(), a.end());

  vector<int> dp(MAX_N+1);
  for (int i = 1; i <= MAX_N; ++i) {
    dp[i] += count[i];
    for (int j = i+i; j <= MAX_N; j += i) {
      dp[j] = max(dp[j], dp[i]);
    }
  }

  int include = *max_element(dp.begin(), dp.end());
  int ans = n - include;
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
