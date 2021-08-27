#include <bits/stdc++.h>

using namespace std;

// Minimum Number of Refueling Stops
//
// when car gets to position
// add the most fuel station for all stations before current position

class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int pos = startFuel;
    int i = 0, n = stations.size();
    int ans = 0;
    priority_queue<int> pq;
    while (pos < target) {
      while (i < n && stations[i][0] <= pos) pq.push(stations[i++][1]);
      if (pq.empty()) return -1;
      pos += pq.top();
      pq.pop();
      ans++;
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> stations = {{50, 50}};
  int ans = Solution().minRefuelStops(100, 50, stations);
  assert(ans == 1);

  return 0;
}
