#include <bits/stdc++.h>

using namespace std;

// The Skyline Problem
//
// look at the building as 2 separate line
// the lines are always paired
// we need to make the left line go before the right line
// so that the right line is paired with the left line
// => sort the lines using x coordinate
//   if x is the same, some building's left line should go first
//   here a trick is to make the right line height negative
//   so when x is the same, just compare the height
//
// when we see a left line, if it's higher than the highest heights
// add it to answer
// when we see a right line, remove the paired left line first,
// if right line is higher than the highest heights,
// add it to answer

struct KeyPoint {
  int x, h;
};

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<KeyPoint> key_points;
    for (vector<int>& building : buildings) {
      int l = building[0], r = building[1], height = building[2];
      key_points.push_back(KeyPoint{l, height});
      key_points.push_back(KeyPoint{r, -height});
    }
    sort(key_points.begin(), key_points.end(), [&](auto& p1, auto& p2) {
      return p1.x == p2.x ? p1.h > p2.h : p1.x < p2.x;
    });

    vector<vector<int>> ans;
    multiset<int> heights;
    heights.insert(0);
    for (auto [x, h] : key_points) {
      if (h > 0) {
        if (h > *heights.rbegin()) {
          ans.push_back({x, h});
        }
        heights.insert(h);
      } else if (h < 0) {
        auto p = heights.find(-h);
        heights.erase(p);
        if (-h > *heights.rbegin()) {
          ans.push_back({x, *heights.rbegin()});
        }
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> buildings = {
      {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  vector<vector<int>> ans = Solution().getSkyline(buildings);
  vector<vector<int>> target = {{2, 10},  {3, 15}, {7, 12}, {12, 0},
                                {15, 10}, {20, 8}, {24, 0}};
  for (int i = 0; i < ans.size(); ++i) {
    assert(ans[i][0] == target[i][0]);
    assert(ans[i][1] == target[i][1]);
  }
  return 0;
}
