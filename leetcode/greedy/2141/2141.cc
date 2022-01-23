#include <bits/stdc++.h>

using namespace std;

// Maximum Running Time of N Computers
//
// this one is pretty hard to come up with the idea
// the main idea is
// if there is a battery that has battery life longer than the current average battery life
// it means we can take this battery and pair it with a computer
// and it will last longer than the average
// basically reduce the problem to n-1 and 1 less battery to consider
// the final answer is the average battery life

class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    long total = accumulate(batteries.begin(), batteries.end(), 0L);
    sort(batteries.rbegin(), batteries.rend());
    int i = 0;
    for (; i < batteries.size() && (batteries[i] > total / (n - i)); ++i) {
      total -= batteries[i];
    }
    return total / (n - i);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 2;
  vector<int> batteries = {3, 3, 3};
  int ans = Solution().maxRunTime(n, batteries);
  assert(ans == 4);

  n = 2;
  batteries = {31, 87, 85, 44, 47, 25};
  ans = Solution().maxRunTime(n, batteries);
  assert(ans == 159);

  n = 9;
  batteries = {18, 54, 2, 53, 87, 31, 71, 4, 29, 25};
  ans = Solution().maxRunTime(n, batteries);
  assert(ans == 6);

  n = 2;
  batteries = {1, 1, 1, 1};
  ans = Solution().maxRunTime(n, batteries);
  assert(ans == 2);

  n = 3;
  batteries = {10, 10, 3, 5};
  ans = Solution().maxRunTime(n, batteries);
  assert(ans == 8);

  return 0;
}
