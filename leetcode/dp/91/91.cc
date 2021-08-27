#include <bits/stdc++.h>

using namespace std;

// Decode Ways
//
// dp[i] means number of ways to decode string s up to i
// if s[i] is not '0': number of ways is dp[i-1]
// and check the case for 10 ~ 26

class Solution {
 public:
  int numDecodings(const string& s) {
    int n = s.length();
    if (n == 0) return 0;

    vector<int> dp(n);
    dp[0] = s[0] != '0';
    for (int i = 1; i < n; ++i) {
      if (s[i] != '0')
        dp[i] += dp[i-1];
      if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6'))
        dp[i] += i >= 2 ? dp[i-2] : 1;
    }
    return dp.back();
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int ans = 0;
  string s;
  s = "12";
  ans = Solution().numDecodings(s);
  assert(ans == 2);

  s = "226";
  ans = Solution().numDecodings(s);
  assert(ans == 3);

  s = "12345";
  ans = Solution().numDecodings(s);
  assert(ans == 3);

  s = "1222222";
  ans = Solution().numDecodings(s);
  assert(ans == 21);

  s = "262626262626262626262";
  ans = Solution().numDecodings(s);
  assert(ans == 1024);

  s = "0";
  ans = Solution().numDecodings(s);
  assert(ans == 0);

  s = "0001";
  ans = Solution().numDecodings(s);
  assert(ans == 0);

  s = "000026";
  ans = Solution().numDecodings(s);
  assert(ans == 0);

  s = "10";
  ans = Solution().numDecodings(s);
  assert(ans == 1);

  s = "101010101010101010";
  ans = Solution().numDecodings(s);
  assert(ans == 1);

  s = "101020";
  ans = Solution().numDecodings(s);
  assert(ans == 1);

  s = "26110";
  ans = Solution().numDecodings(s);
  assert(ans == 2);

  s = "261105";
  ans = Solution().numDecodings(s);
  assert(ans == 2);

  s = "26110559717";
  ans = Solution().numDecodings(s);
  assert(ans == 4);

  s = "2611055971756562";
  ans = Solution().numDecodings(s);
  assert(ans == 4);

  s = "17";
  ans = Solution().numDecodings(s);
  assert(ans == 2);

  s = "117";
  ans = Solution().numDecodings(s);
  assert(ans == 3);
  return 0;
}
