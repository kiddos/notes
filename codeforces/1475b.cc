#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> memo(1000001, -1);
  function<bool(int)> dp = [&](int num) {
    if (num == 0) return true;
    if (num < 0) return false;
    if (memo[num] >= 0) return (bool)memo[num];
    bool ans = dp(num - 2020) || dp(num - 2021);
    memo[num] = ans;
    return ans;
  };

  int n = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int num = 0;
    cin >> num;
    if (dp(num)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
