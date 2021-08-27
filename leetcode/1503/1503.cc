#include <bits/stdc++.h>

using namespace std;

// Last Moment Before All Ants Fall Out of a Plank
//
// the most confusing part is
// "When two ants moving in two different directions meet at some point, they
// change their directions and continue moving again.
//
// this is actually the same as switching from left side to right side
// it doesn't affect the final answer anyway

class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int ans = 0;
    for (int l : left) ans = max(ans, l);
    for (int r : right) ans = max(ans, n - r);
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> left = {4, 3};
  vector<int> right = {0, 1};
  int ans = Solution().getLastMoment(4, left, right);
  assert(ans == 4);

  return 0;
}
