#include <bits/stdc++.h>

using namespace std;

// Decoded String at Index
//
// compute the total length of the string first and then trace backwards

class Solution {
 public:
  string decodeAtIndex(string S, int K) {
    long long total = 0, n = S.length();
    for (int i = 0; i < S.length(); ++i) {
      total = isdigit(S[i]) ? total * (S[i]-'0') : total+1;
    }
    for (int i = n-1; i >= 0; --i) {
      if (isdigit(S[i])) {
        total /= (S[i] - '0');
        K %= total;
      } else if (total != 0 && K % total-- == 0) {
        return S.substr(i, 1);
      }
    }
    return "";
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S = "leet2code3";
  int K = 10;
  string ans = Solution().decodeAtIndex(S, K);
  assert(ans == "o");

  S = "ha22";
  K = 5;
  ans = Solution().decodeAtIndex(S, K);
  assert(ans == "h");

  S = "a2345678999999999999999";
  K = 1;
  ans = Solution().decodeAtIndex(S, K);
  assert(ans == "a");
  return 0;
}
