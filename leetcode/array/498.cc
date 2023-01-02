#include <bits/stdc++.h>

using namespace std;

struct Element {
  int level;
  int k;
  int val;
};

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<Element> elements;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int level = i+j;
        int k = level % 2 == 0 ? j : i;
        int val = matrix[i][j];
        elements.push_back(Element{level, k, val});
      }
    }

    sort(elements.begin(), elements.end(), [](auto& e1, auto& e2) {
      if (e1.level == e2.level) {
        return e1.k < e2.k;
      }
      return e1.level < e2.level;
    });

    vector<int> ans;
    for (auto& e : elements) {
      ans.push_back(e.val);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> matrix = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
  vector<int> ans = Solution().findDiagonalOrder(matrix);
  vector<int> expected = { 1,2,4,7,5,3,6,8,9 };

  assert(ans.size() == expected.size());
  for (int i = 0; i < ans.size(); ++i) {
    assert(ans[i] == expected[i]);
  }

  return 0;
}
