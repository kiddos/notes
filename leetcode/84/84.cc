#include <bits/stdc++.h>

using namespace std;

// Largest Rectangle in Histogram
//
// keep an increasing stack of index
// so for every index[i-1] to index[i]
// every height is at least heights[index[i-1]]

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    int n = heights.size(), ans = 0;
    vector<int> index;
    for (int i = 0; i < n; ++i) {
      if (index.empty() || heights[i] >= heights[index.back()]) {
        index.push_back(i);
      } else {
        int h = heights[index.back()];
        index.pop_back();
        int width = i - (index.empty() ? 0 : index.back() + 1);
        ans = max(ans, h * width);
        i--;
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> heights = {2, 1, 5, 6, 2, 3};

  int ans = Solution().largestRectangleArea(heights);
  assert(ans == 10);

  heights = {1};
  ans = Solution().largestRectangleArea(heights);
  assert(ans == 1);

  heights = {9, 8, 8, 6, 5, 8, 7, 8, 5, 2, 4, 0, 4, 6};
  ans = Solution().largestRectangleArea(heights);
  assert(ans == 45);
  return 0;
}
