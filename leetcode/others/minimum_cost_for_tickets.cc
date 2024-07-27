#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    memo_ = vector<int>(366, -1);
    unordered_set<int> day_set;
    for (int d : days) day_set.insert(d);
    return mincost(day_set, costs, 0);
  }


 private:
  int mincost(unordered_set<int>& days, vector<int>& costs, int d) {
    if (d >= 366) return 0;

    if (memo_[d] >= 0) return memo_[d];

    int cost = 0;
    if (days.count(d)) {
      cost = min({costs[0] + mincost(days, costs, d+1),
                  costs[1] + mincost(days, costs, d+7),
                  costs[2] + mincost(days, costs, d+30)});
    } else {
      cost = mincost(days, costs, d+1);
    }
    memo_[d] = cost;
    return cost;
  }

  vector<int> memo_;
};

int main(void) {
  vector<int> days = { 1, 4, 6, 7, 8, 20 };
  vector<int> costs = { 2, 7, 15 };
  int ans = Solution().mincostTickets(days, costs);
  cout << ans << endl;
  return 0;
}
