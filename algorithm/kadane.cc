#include <bits/stdc++.h>

using namespace std;

// does not allow empty subarray
int max_continuous_subarray(vector<int>& nums) {
  int current_max = 0;
  int global_max = numeric_limits<int>::min();
  for (int n : nums) {
    current_max = max(current_max + n, n);
    global_max = max(global_max, current_max);
  }
  return global_max;
}

// allow empty subarray
int max_continuous_subarray_allow_empty(vector<int>& nums) {
  int current_max = 0;
  int global_max = 0;
  for (int n : nums) {
    current_max = max(0, current_max + n);
    global_max = max(global_max, current_max);
  }
  return global_max;
}

int main(void) {
  uniform_int_distribution<int> dist(-100, 100);
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

  const int n = 16;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) nums[i] = dist(gen);

  for (int i = 0; i < n; ++i) {
    cout << setw(3) << nums[i] << " ";
  }
  cout << endl;

  cout << max_continuous_subarray(nums) << endl;
  cout << max_continuous_subarray_allow_empty(nums) << endl;

  // vector<int> dp(n+1);
  // for (int i = 0; i < n; ++i) {
  //   dp[i+1] = max(dp[i] + nums[i], nums[i]);
  // }


  // for (int i = 1; i <= n; ++i) {
  //   cout << setw(3) << dp[i] << " ";
  // }
  // cout << endl;
  return 0;
}
