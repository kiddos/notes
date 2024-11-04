#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }

  int i = 0;
  vector<vector<int>> intelligence_checks, strength_checks;
  while (i < n && r[i] != 0) i++;
  while (i < n) {
    vector<int> intelligence_check(m+1);
    vector<int> strength_check(m+1);
    int j = i+1;
    while (j < n && r[j] != 0) {
      if (r[j] > 0) {
        intelligence_check[r[j]]++;
      } else if (r[j] < 0) {
        strength_check[-r[j]]++;
      }
      j++;
    }

    strength_checks.push_back(strength_check);
    intelligence_checks.push_back(intelligence_check);
    i = j;
  }

  auto prefix_sum = [&](vector<vector<int>>& checks) {
    for (vector<int>& c : checks) {
      for (int i = 1; i <= m; ++i) {
        c[i] += c[i-1];
      }
    }
  };
  prefix_sum(intelligence_checks);
  prefix_sum(strength_checks);

  auto get_passed = [&](int i, int intelligence, int strength) -> int {
    return intelligence_checks[i][intelligence] + strength_checks[i][strength];
  };

  vector<vector<int>> memo(m+1, vector<int>(m+1, -1));
  function<int(int,int)> dp = [&](int i, int intelligence) -> int {
    if (i == m) {
      return 0;
    }
    if (memo[i][intelligence] >= 0) {
      return memo[i][intelligence];
    }
    int ans1 = dp(i+1, intelligence + 1) + get_passed(i, intelligence + 1, i - intelligence);
    int ans2 = dp(i+1, intelligence) + get_passed(i, intelligence, i + 1 - intelligence);
    return memo[i][intelligence] = max(ans1, ans2);
  };

  int ans = dp(0, 0);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
