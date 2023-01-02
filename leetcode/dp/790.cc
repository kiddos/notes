#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

class Solution {
 public:
  int numTiling(int N) {
    vector<int64_t> f(1001), g(1001);
    f[1] = g[1] = 1;
    f[2] = g[2] = 2;
    for (int i = 3; i <= N; ++i) {
      g[i] = (f[i-1] + g[i-1]) % MOD;
      f[i] = (f[i-1] + f[i-2] + g[i-2] * 2) % MOD;
    }
    return f[N];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int ans = Solution().numTiling(3);
  assert(ans == 5);

  ans = Solution().numTiling(10);
  assert(ans == 1255);

  ans = Solution().numTiling(100);
  assert(ans == 190242381);

  ans = Solution().numTiling(1000);
  assert(ans == 979232805);

  ans = Solution().numTiling(999);
  assert(ans == 326038248);

  return 0;
}
