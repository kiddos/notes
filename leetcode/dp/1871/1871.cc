#include <bits/stdc++.h>

using namespace std;

// Jump Game VII

// my original solution using set
class Solution0 {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.length();
    set<int> can_jump;
    can_jump.insert(0);
    for (int i = 1; i < n; ++i) {
      if (s[i] == '0') {
        auto p1 = can_jump.upper_bound(i - minJump);
        auto p2 = can_jump.lower_bound(i - maxJump);
        if (p1 != can_jump.begin() && p2 != can_jump.end() && *prev(p1) >= *p2)
          can_jump.insert(i);
      }
    }

    return can_jump.count(n - 1);
  }
};

// dp solution
// keep track the number of available jumps in the interval from [i - maxJump, i
// - minJump]
class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.length();
    vector<bool> dp(n);
    dp[0] = true;
    int count = 0;
    for (int i = 1; i < n; ++i) {
      if (i >= minJump) count += dp[i - minJump];
      if (i > maxJump) count -= dp[i - maxJump - 1];
      if (s[i] == '0' && count > 0) dp[i] = true;
    }
    return dp.back();
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "011010";
  bool ans = Solution().canReach(s, 2, 3);
  assert(ans);

  s = "01101110";
  ans = Solution().canReach(s, 2, 3);
  assert(!ans);

  return 0;
}
