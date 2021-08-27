#include <bits/stdc++.h>

using namespace std;

// Magnetic Force Between Two Balls
//
// idea is to binary search if we can place m ball with distance d apart given positions

class Solution {
 public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());

    function<bool(int)> can_place = [&](int d) {
      int last_placed = position[0];
      int count = 1;
      for (int pos : position) {
        if (pos >= last_placed + d) {
          last_placed = pos;
          count++;
        }
        if (count >= m) return true;
      }
      return false;
    };

    int l = 1, r = position.back();
    int ans = 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (can_place(m)) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> position = {269826447, 974181916, 225871443, 189215924,
                          664652743, 592895362, 754562271, 335067223,
                          996014894, 510353008, 48640772,  228945137};
  int m = 3;
  int ans = Solution().maxDistance(position, m);
  assert(ans == 461712236);

  position = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  m = 4;
  ans = Solution().maxDistance(position, m);
  assert(ans == 3);

  // code here...
  return 0;
}
