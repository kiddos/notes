#include <bits/stdc++.h>

using namespace std;

// Kth Smallest Element in a Sorted Matrix
//
// idea is to push first element of each row into the priority_queue
// remove the first smallest k-1 element from priority_queue
// when a row element gets remove, put the next element from this row

struct Row {
  int r, c;
  int val;
};

struct Compare {
  bool operator()(const Row& r1, const Row& r2) { return r1.val > r2.val; }
};

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<Row, vector<Row>, Compare> pq;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
      pq.push(Row{i, 0, matrix[i][0]});
    }
    for (int kk = 0; kk < k - 1; ++kk) {
      auto row = pq.top();
      pq.pop();
      if (row.c < n - 1)
        pq.push(Row{row.r, row.c + 1, matrix[row.r][row.c + 1]});
    }
    return pq.top().val;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  int k = 8;
  int ans = Solution().kthSmallest(matrix, k);
  assert(ans == 13);
  return 0;
}
