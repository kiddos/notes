#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int countVowelStrings(int n) {
    vector<int> count(5, 1);
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < 5; ++j) {
        count[j] += count[j-1];
      }
    }
    int ans = 0;
    for (int c : count) ans += c;
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int ans;
  ans = Solution().countVowelStrings(1);
  assert(ans == 5);

  ans = Solution().countVowelStrings(2);
  assert(ans == 15);

  ans = Solution().countVowelStrings(3);
  assert(ans == 35);

  ans = Solution().countVowelStrings(50);
  assert(ans == 316251);
  return 0;
}
