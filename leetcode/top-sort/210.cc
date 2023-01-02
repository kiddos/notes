#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;
    vector<vector<int>> adj(n);
    for (vector<int>& p : prerequisites) {
      adj[p[1]].push_back(p[0]);
    }

    vector<bool> visited(n), recur(n);
    vector<int> order;
    for (int i = 0; i < n; ++i) {
      if (!dfs(adj, i, visited, recur, order)) return {};
    }
    reverse(order.begin(), order.end());
    return order;
  }

 private:
  bool dfs(vector<vector<int>>& adj, int course, vector<bool>& visited, vector<bool>& recur, vector<int>& order) {
    if (recur[course]) return false;
    if (visited[course]) return true;

    recur[course] = true;
    visited[course] = true;
    for (int next_course : adj[course]) {
      if (!dfs(adj, next_course, visited, recur, order)) return false;
    }

    order.push_back(course);
    recur[course] = false;
    return true;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int numCourses = 4;
  vector<vector<int>> prerequisites = {{ 1,0 },{ 2,0 },{ 3,1 },{ 3,2 }};
  vector<int> ans = Solution().findOrder(numCourses, prerequisites);
  vector<int> target = {0, 2, 1, 3};
  for (int i = 0; i < ans.size(); ++i) assert(ans[i] == target[i]);

  // code here...
  return 0;
}
