#include <bits/stdc++.h>

using namespace std;

// Construct String With Repeat Limit
//
// greedy
// fill in the characters from z -> a
// if the current character to fill is not the last character and there are still some last character left
// only fill 1

class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    vector<int> count(26);
    for (char c : s) count[c - 'a']++;
    string ans;
    while (true) {
      bool add_one = false;
      char c = 'z';
      while (c >= 'a' &&
             ((!ans.empty() && c == ans.back()) || !count[c - 'a'])) {
        if (!ans.empty() && c == ans.back() && count[c - 'a']) {
          add_one = true;
        }
        c--;
      }
      if (c < 'a' || count[c - 'a'] == 0) break;

      int add_count = add_one ? 1 : min(repeatLimit, count[c - 'a']);
      count[c - 'a'] -= add_count;
      ans += string(add_count, c);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "cczazcc";
  int repeatLimit = 3;
  string ans = Solution().repeatLimitedString(s, repeatLimit);
  assert(ans == "zzcccac");

  s = "aababab";
  repeatLimit = 2;
  ans = Solution().repeatLimitedString(s, repeatLimit);
  assert(ans == "bbabaa");
  return 0;
}
