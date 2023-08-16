#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  i64 ans = 0;
  vector<int> nums;
  for (int i = 0; i < n; ++i) {
    i64 a = 0;
    cin >> a;
    ans += a / k;
    nums.push_back(a % k);
  }

  sort(nums.begin(), nums.end());
  for (int r = n-1, l = 0; r >= l; --r) {
    while (l < r && nums[l] + nums[r] < k) {
      l++;
    }
    if (l < r) {
      ans++;
      l++;
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
