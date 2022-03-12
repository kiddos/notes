#include <bits/stdc++.h>

using namespace std;

// Reverse Pairs
//
// the idea is to merge sort the array
// find the number of numbers in the first half of the array that is > 2 *
// nums[j] we can use binary search for that since the first half is already
// sorted

typedef long long ll;

class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    auto find_first = [&](int l, int r, ll val) {
      int index = -1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if ((ll)nums[m] >= val) {
          index = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      return index;
    };

    int ans = 0;
    function<void(int, int)> merge_sort = [&](int l, int r) {
      if (l >= r) return;
      int m = l + (r - l) / 2;
      merge_sort(l, m);
      merge_sort(m + 1, r);
      vector<int> output(r - l + 1);
      for (int i = l, j = m + 1, k = 0; i <= m || j <= r;) {
        ll a = i <= m ? nums[i] : numeric_limits<ll>::max();
        ll b = j <= r ? nums[j] : numeric_limits<ll>::max();
        if (b <= a) {
          output[k++] = b;
          j++;
          int index = find_first(l, m, 2 * b + 1);
          if (index >= 0) {
            ans += m - index + 1;
          }
        } else {
          output[k++] = a;
          i++;
        }
      }
      move(output.begin(), output.end(), nums.begin() + l);
    };
    int n = nums.size();
    merge_sort(0, n - 1);
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> nums = {1, 3, 2, 3, 1};
  int ans = Solution().reversePairs(nums);
  assert(ans == 2);

  nums = {2, 4, 3, 5, 1};
  ans = Solution().reversePairs(nums);
  assert(ans == 3);
  return 0;
}
