#include <bits/stdc++.h>

using namespace std;

// Minimum Cost to Hire K Workers
//
// the idea is to sort the workers by their quality / wage descreasing
// and we know the minimum to pay is current total quality / that ratio
// always pops out the max quality to get the minimum pay

class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    vector<pair<int, int>> workers;
    int n = quality.size();
    for (int i = 0; i < n; ++i) {
      workers.push_back({quality[i], wage[i]});
    }
    sort(workers.begin(), workers.end(), [&](auto& w1, auto& w2) {
      return (double)w1.first / w1.second > (double)w2.first / w2.second;
    });

    priority_queue<int, vector<int>, less<int>> pq;
    double total_quality = 0, ans = DBL_MAX;
    for (int i = 0; i < n; ++i) {
      total_quality += workers[i].first;
      pq.push(workers[i].first);
      if (pq.size() >= k) {
        double wages = total_quality / workers[i].first * workers[i].second;
        ans = min(ans, wages);

        total_quality -= pq.top();
        pq.pop();
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> quality = {10, 20, 5};
  vector<int> wage = {70, 50, 30};
  int k = 2;
  double ans = Solution().mincostToHireWorkers(quality, wage, k);
  assert(abs(ans - 105) <= 1e-5);

  quality = {3, 1, 10, 10, 1};
  wage = {4, 8, 2, 2, 7};
  k = 3;
  ans = Solution().mincostToHireWorkers(quality, wage, k);
  assert(abs(ans - 30.66667) <= 1e-4);

  return 0;
}
