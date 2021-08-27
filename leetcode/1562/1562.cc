#include <bits/stdc++.h>

using namespace std;

// Find Latest Group of Size M
//
// keep the length of 1's
// very similar to keeping boundaries
//
// so when we have [, ...,0,1,1,1,0,1,1,1,0,...]
//                                i
//
// ->length[i-1] = 3 and length[i+1] = 3
// going to        [, ...,0,1,1,1,1,1,1,1,0,...]
// ->length[i] = length[i-3] = length[i+3] = 3 + 3 + 1 = 7

class Solution {
 public:
  int findLatestStep(vector<int>& arr, int m) {
    int ans = -1, n = arr.size();
    vector<int> length(n + 2), count(n + 1);
    for (int i = 0; i < n; ++i) {
      int a = arr[i], left = length[a - 1], right = length[a + 1];
      length[a] = length[a - left] = length[a + right] = left + right + 1;
      count[left]--;
      count[right]--;
      count[length[a]]++;
      if (count[m] > 0) {
        ans = i + 1;
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> arr = {3, 5, 1, 2, 4};
  int m = 1;
  int ans = Solution().findLatestStep(arr, m);
  assert(ans == 4);

  return 0;
}
