#include <bits/stdc++.h>

using namespace std;

// Jump Game IV
//
// think bfs would solve this

class Solution {
 public:
  int minJumps(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> indices;
    for (int i = 0; i < n; ++i) {
      indices[arr[i]].push_back(i);
    }

    queue<int> q({0});
    vector<bool> visited(n);
    visited[0] = true;
    int current = 0;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int index = q.front();
        q.pop();
        if (index == n - 1) return current;

        vector<int>& next = indices[arr[index]];
        next.push_back(index + 1);
        next.push_back(index - 1);
        for (int j : next) {
          if (j != index && j >= 0 && j < n && !visited[j]) {
            visited[j] = true;
            q.push(j);
          }
        }
        next.clear();
      }
      current++;
    }
    return n - 1;
  }

 private:
  vector<int> data_;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> arr;
  int ans = 0;

  arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
  ans = Solution().minJumps(arr);
  assert(ans == 3);

  arr = {7, 6, 9, 6, 9, 6, 9, 7};
  ans = Solution().minJumps(arr);
  assert(ans == 1);

  arr = {11, 22, 7, 7, 7, 7, 7, 7, 7, 22, 13};
  ans = Solution().minJumps(arr);
  assert(ans == 3);

  arr = {6, 1, 9};
  ans = Solution().minJumps(arr);
  assert(ans == 2);

  arr = {1};
  ans = Solution().minJumps(arr);
  assert(ans == 0);
  return 0;
}
