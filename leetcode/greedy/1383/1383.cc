#include <bits/stdc++.h>

using namespace std;

// Maximum Performance of a Team
//
// the strategy is to hire the most efficient engineers first
// and lay off the engineers with the least speed

class Solution {
 public:
  long maxPerformance(vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> engineers;
    int n = speed.size();
    for (int i = 0; i < n; ++i) {
      engineers.push_back({efficiency[i], speed[i]});
    }
    sort(engineers.rbegin(), engineers.rend());

    priority_queue<int, vector<int>, greater<int>> pq;
    long total_speed = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      pq.push(engineers[i].second);
      total_speed += engineers[i].second;
      if (pq.size() > k) {
        total_speed -= pq.top();
        pq.pop();
      }
      ans = max(ans, total_speed * engineers[i].first);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> speed = {2, 10, 3, 1, 5, 8};
  vector<int> efficiency = {5, 4, 3, 9, 7, 2};
  int k = 3;

  long ans = Solution().maxPerformance(speed, efficiency, k);
  assert(ans == 68);
  return 0;
}
