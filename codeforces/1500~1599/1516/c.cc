#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool can_divide(vector<int>& a, int ignore) {
  int n = a.size();
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if (i == ignore) {
      continue;
    }
    sum += a[i];
  }

  if (sum % 2 == 1) {
    return false;
  }

  int target = sum / 2;
  vector<bool> dp(target+1);

  dp[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int t = target; t >= 0; --t) {
      if (dp[t] && t+a[i] <= target) {
        dp[t+a[i]] = true;
      }
    }
  }
  return dp[target];
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (!can_divide(a, -1)) {
    cout << "0" << endl;
    return;
  }
  
  for (int i = 0; i < n; ++i) {
    if (!can_divide(a, i)) {
      cout << "1" << endl;
      cout << i+1 << endl;
      return;
    }
  }

  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
