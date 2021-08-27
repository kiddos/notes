#include <bits/stdc++.h>

using namespace std;

// Remove Boxes
//
// this one is super hard
//
// first try brute force but it will TLE
//
// this of this problem this way
// we can always greedy remove consecutive boxes
// => for starting box s1, we can remove all consecutive box that is the same with s
// for the rest of the box starting at s2 (where s2 is not s1)
//   if the box is the same as s1
//     we can continue to count boxes same as s1 to get larger points
//     and also remove the same box for s2 and get the score for s2

class Solution {
 public:
  int removeBoxes(vector<int>& boxes) {
    int n = boxes.size();
    vector<vector<vector<int>>> memo(
        n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
    function<int(int, int, int)> dp = [&](int l, int r, int k) {
      if (l > r) return 0;
      if (memo[l][r][k] >= 0) return memo[l][r][k];
      int box = boxes[l];
      int K = k, s = l, e = r;
      for (; l <= r && boxes[l] == box; ++l, ++k)
        ;
      int ans = dp(l, r, 0) + k * k;
      for (int i = l; i <= r; ++i) {
        if (boxes[i] == box) {
          int points = dp(l, i - 1, 0) + dp(i, r, k);
          ans = max(ans, points);
        }
      }
      return memo[s][e][K] = ans;
    };
    return dp(0, n - 1, 0);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
  int ans = Solution().removeBoxes(boxes);
  assert(ans == 23);
  return 0;
}
