#include <bits/stdc++.h>

using namespace std;

// Non-negative Integers without Consecutive Ones
//
// this one is super hard
//
// to cover 00000 ~ 01111 we can use dp
// dp[i] is the count of numbers that follow the rule without consecutive 1s
// to add 0, the result is dp[i-1]
// to add 1, the result is dp[i-2]
// this is just fibonacci number
// we can compute this first
//
// for number like 10101000
// fib[8] can cover 00000000 ~ 01111111
// fib[6] can cover 00000000 ~ 00011111
// fib[4] can cover 00000000 ~ 00000111
// so the result should be fib[8] + fib[6] + fib[4] + 1 (because 10101000 is also valid)
//
// for number like 10110000
// fib[8] can cover 00000000 ~ 01111111
// fib[6] can cover 00000000 ~ 00011111
// which is all the case for 00000000 ~ 00110000
// because to be valid the number has to be 0010xxxxx which is less than 00110000
// so the result should be fib[8] + fib[6] + 0 (because 10110000 is not balid)


class Solution {
public:
    int findIntegers(int n) {
        vector<int> fib = {1, 1};
        for (int i = 2; i < 32; ++i) fib.push_back(fib[i-1] + fib[i-2]);
        
        int prev_bit = 0;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            if (n & (1 << i)) {
                ans +=  fib[i+1];
                if (prev_bit) return ans;
                prev_bit = 1;
            } else {
                prev_bit = 0;
            }
        }
        return ans + 1;
    }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int ans = Solution().findIntegers(1);
  assert(ans == 2);

  ans = Solution().findIntegers(2);
  assert(ans == 3);

  ans = Solution().findIntegers(10);
  assert(ans == 8);


  return 0;
}
