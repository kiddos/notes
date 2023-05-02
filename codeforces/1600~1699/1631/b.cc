#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int n = nums.size();
  int last = nums.back();
  int i = n-1;
  int ans = 0;
  while (i >= 0) {
    while (i >= 0 && nums[i] == last) {
      i--;
    }
    if (i >= 0) {
      int turn = n - i - 1;
      i -= turn;
      ans++;
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int ans = solve(nums);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
