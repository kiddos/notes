#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto i1, auto i2) {
      return i1[1] < i2[1];
    });

    int to_remove = 0;
    int last_end = numeric_limits<int>::min();
    for (auto i : intervals) {
      if (i[0] >= last_end) {
        last_end = max(last_end, i[1]);
      } else {
        to_remove ++;
      }
    }
    return to_remove;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<vector<int>> intervals(n);
    for (int i = 0; i < n; ++i) {
      int start = 0, end = 0;
      cin >> start >> end;
      intervals[i] = {start, end};
    }

    int ans = Solution().eraseOverlapIntervals(intervals);
    cout << ans << endl;
  }

  return 0;
}
