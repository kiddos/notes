#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n) {
    for (int i = 0; i < n; ++i) {
      parent_[i] = i;
    }
  }

  int Find(int i) {
    if (parent_[i] == i) return i;
    return Find(parent_[i]);
  }

  void Union(int x, int y) {
    parent_[Find(x)] = parent_[Find(y)];
  }

 private:
  vector<int> parent_;
};

class Solution {
 public:
  int largestComponentSize(vector<int>& nums) {
    int n = *max_element(nums.begin(), nums.end());
    DisjointSet set(n+1);

    for (int num : nums) {
      for (int k = 2; k <= sqrt(num); ++k) {
        if (num % k == 0) {
          set.Union(num, k);
          set.Union(num, num / k);
        }
      }
    }

    int ans = 0;
    unordered_map<int, int> count;
    for (int num : nums) {
      count[set.Find(num)]++;
      ans = max(ans, count[set.Find(num)]);
    }
    return ans;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    int ans = Solution().largestComponentSize(nums);
    cout << ans << endl;
  }
  return 0;
}
