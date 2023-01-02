#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
   int minStickers(vector<string>& stickers, string target) {
     int n = target.length(), m = 1 << target.length();
     vector<int> dp(m, numeric_limits<int>::max());
     dp[0] = 0;
     for (int i = 0; i < m; ++i) {
       if (dp[i] == numeric_limits<int>::max()) continue;
       for (string& sticker: stickers) {
         int index = i;
         for (char c : sticker) {
           for (int j = 0; j < n; ++j) {
             if (target[j] == c && !((index >> j) & 1)) {
               index |= (1<<j);
               break;
             }
           }
         }
         dp[index] = min(dp[index], dp[i]+1);
       }
     }

     return dp.back() == numeric_limits<int>::max() ? -1 : dp.back();
   }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<string> stickers = {"with", "example", "science"};
  string target = "thehat";

  int ans = Solution().minStickers(stickers, target);
  assert(ans == 3);

  stickers = {"notice", "possible"};
  target = "basicbasic";
  ans = Solution().minStickers(stickers, target);
  assert(ans == -1);

  return 0;
}
