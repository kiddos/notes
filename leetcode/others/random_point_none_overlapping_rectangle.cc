#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  Solution(vector<vector<int>>& rects) {
    int sum_area = 0;
    for (auto rect : rects) {
      int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
      sum_area += area;
      rects_.emplace(sum_area, rect);
    }
    sum_area_ = sum_area;
  }

  vector<int> pick() {
    int a = rand() % sum_area_;
    auto it = rects_.upper_bound(a);
    vector<int> rect = it->second;
    int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
    int y = rand() % (rect[3] - rect[1] + 1) + rect[1];
    return { x, y };
  }

 private:
  multimap<int, vector<int>> rects_;
  int sum_area_;
};

int main(void) {
  vector<vector<int>> rects = {{-2, -2, -1, -1}, {1, 0, 3, 0}};
  Solution solution(rects);
  for (int i = 0; i < 5; ++i) {
    auto coord = solution.pick();
    cout << "(" << coord[0] << "," << coord[1] << ") ";
  }
  cout << endl;
  return 0;
}
