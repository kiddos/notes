#include <bits/stdc++.h>

using namespace std;

// Palindrome Partitioning II
// 
// solution 1
//
// compute is_palindrome[i][j] first
// is_palindrome[i][j] = true if s[i][j] is palindrome
//
// dp[i] is the min len to cut
// for j before i
//  if is_palindrome[j+1][i]:
//    dp[i] = min(dp[i], dp[j]+1)

class Solution {
 public:
  int minCut(const string& s) {
    int n = s.length();
    vector<vector<int>> is_palindrome(n, vector<int>(n, true));
    for (int len = 1; len < n; ++len) {
      for (int i = 0; i + len < n; ++i) {
        int j = i + len;
        is_palindrome[i][j] = is_palindrome[i + 1][j - 1] && s[i] == s[j];
      }
    }

    vector<int> dp(n, n);
    for (int i = 0; i < n; ++i) {
      if (is_palindrome[0][i]) {
        dp[i] = 0;
      } else {
        for (int j = 0; j < i; ++j) {
          if (is_palindrome[j + 1][i]) {
            dp[i] = min(dp[i], dp[j] + 1);
          }
        }
      }
    }
    return dp.back();
  }
};

// solution 2
//
// this the "push" dp version
// dp[n] = the min cut for cutting s[0, n-1]
//
// odd length case:
// if s[i-j:i+j] is palindrome:
//  dp[i+j+1] = min(dp[i+j+1], dp[i-j]+1)
//
// even length case:
// if s[i-j+1:i+j] is palindrome:
//  dp[i+j+1] = min(dp[i+j+1], dp[i-j+1]+1)

class Solution2 {
 public:
  int minCut(const string& s) {
    int n = s.length();
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; ++i) dp[i] = i - 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; i + j < n && i - j >= 0 && s[i + j] == s[i - j]; ++j) {
        dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
      }
      for (int j = 1; i + j < n && i - j + 1 >= 0 && s[i + j] == s[i - j + 1];
           ++j) {
        dp[i + j + 1] = min(dp[i + j + 1], dp[i - j + 1] + 1);
      }
    }
    return dp[n];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "aab";
  int ans = Solution().minCut(s);
  assert(ans == 1);
  ans = Solution2().minCut(s);
  assert(ans == 1);

  s = "a";
  ans = Solution().minCut(s);
  assert(ans == 0);
  ans = Solution2().minCut(s);
  assert(ans == 0);

  s = "ab";
  ans = Solution().minCut(s);
  assert(ans == 1);
  ans = Solution2().minCut(s);
  assert(ans == 1);

  s = "apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfl"
      "jwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzig"
      "sxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbf"
      "eebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxs"
      "eeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrm"
      "shjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgke"
      "zvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
  ans = Solution().minCut(s);
  assert(ans == 452);
  ans = Solution2().minCut(s);
  assert(ans == 452);

  s = "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehi"
      "eabbdfeigbiaggchaeghaijfbjhi";
  ans = Solution().minCut(s);
  assert(ans == 75);
  ans = Solution2().minCut(s);
  assert(ans == 75);
  return 0;
}
