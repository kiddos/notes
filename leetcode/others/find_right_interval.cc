#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    map<int, int> m;
    int n = intervals.size();
    for (int i = 0; i < n; ++i) {
      m[intervals[i][0]] = i;
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      auto it = m.lower_bound(intervals[i][1]);
      if (it == m.end()) ans.push_back(-1);
      else ans.push_back(it->second);
    }
    return ans;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<vector<int>> intervals;
    for (int i = 0; i < n; ++i) {
      vector<int> interval(2);
      cin >> interval[0] >> interval[1];
      intervals.push_back(interval);
    }

    vector<int> ans = Solution().findRightInterval(intervals);
    for (int a : ans) cout << a << " ";
    cout << endl;
  }
  return 0;
}
