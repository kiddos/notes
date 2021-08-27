#include <bits/stdc++.h>

using namespace std;

// Task Scheduler
//
// need to be greedy and fill in most occur task first
// so when n = 2
// fill in like
// A . . A . . A
// and then fill in other tasks
// A B . A B . A B
// A B C A B C A B C
//
// so the answer will be (max_occur_count) * (n+1) + the number of task that occur == max_occur
// one final edge case is when tasks there is no enough space to fill in the tasks
// just return total task count in that case

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26);
    int max_count = 0;
    for (char t : tasks) {
      count[t - 'A']++;
      max_count = max(max_count, count[t - 'A']);
    }

    int ans = (max_count - 1) * (n + 1);
    for (int t = 0; t < 26; ++t) {
      if (count[t] == max_count) ans++;
    }
    return max((int)tasks.size(), ans);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;
  int ans = Solution().leastInterval(tasks, n);
  assert(ans == 8);
  return 0;
}
