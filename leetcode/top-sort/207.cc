#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;
    vector<vector<int>> adj(n);
    for (vector<int>& p : prerequisites) {
      adj[p[1]].push_back(p[0]);
    }

    vector<bool> visited(n);
    for (int i = 0; i < n; ++i) {
      vector<bool> recur(n);
      if (!dfs(adj, i, visited, recur)) return false;
    }
    return true;
  }

 private:
  bool dfs(vector<vector<int>>& adj, int start, vector<bool>& visited, vector<bool>& recur) {
    if (recur[start]) return false;
    if (visited[start]) return true;

    visited[start] = recur[start] = true;
    for (int next : adj[start]) {
      if (!dfs(adj, next, visited, recur)) return false;
    }
    recur[start] = false;
    return true;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}
