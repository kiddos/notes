#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  bool dfs(int course, vector<bool>& visited, vector<bool>& recur, vector<vector<int>>& adj, vector<int>& ans) {
    if (recur[course]) return false;
    if (visited[course]) return true;

    visited[course] = true;
    recur[course] = true;
    for (int p : adj[course]) {
      if (!dfs(p, visited, recur, adj, ans)) return false;
    }
    recur[course] = false;
    ans.push_back(course);
    return true;
  }

  vector<int> FindOrder(int n, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(n);
    for (pair<int, int> p : prerequisites) {
      adj[p.first].push_back(p.second);
    }

    vector<int> ans;
    vector<bool> visited(n);
    for (int i = 0; i < n; ++i) {
      vector<bool> recur(n);
      if (!dfs(i, visited, recur, adj, ans)) return {};
    }
    return ans;
  }
};

class Solution2 {
 public:
  bool dfs(int course, vector<int>& visited, vector<vector<int>>& adj, vector<int>& ans) {
    if (visited[course]) {
      return visited[course] == 2;
    }

    visited[course] = 1;
    for (int p : adj[course]) {
      if (!dfs(p, visited, adj, ans)) return false;
    }

    ans.push_back(course);
    visited[course] = 2;
    return true;
  }

  vector<int> FindOrder(int n, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(n);
    for (pair<int, int> p : prerequisites) {
      adj[p.first].push_back(p.second);
    }

    vector<int> ans;
    vector<int> visited(n);
    for (int i = 0; i < n; ++i) {
      if (!dfs(i, visited, adj, ans)) return {};
    }
    return ans;
  }
};

class Solution3 {
 public:
  bool dfs(int course, vector<int>& visited, vector<vector<int>>& adj, stack<int>& order) {
    if (visited[course]) {
      return visited[course] == 2;
    }

    visited[course] = 1;

    for (int p : adj[course]) {
      if (!dfs(p, visited, adj, order)) return false;
    }

    order.push(course);
    visited[course] = 2;
    return true;
  }

  vector<int> FindOrder(int n, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(n);
    for (pair<int, int> p : prerequisites) {
      adj[p.second].push_back(p.first);
    }

    stack<int> s;
    vector<int> visited(n);
    for (int i = 0; i < n; ++i) {
      if (!dfs(i, visited, adj, s)) return {};
    }
    vector<int> ans;
    while (!s.empty()) {
      ans.push_back(s.top());
      s.pop();
    }
    return ans;
  }
};

class Solution4 {
 public:
  vector<int> FindOrder(int n, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for (pair<int, int> p : prerequisites) {
      adj[p.second].push_back(p.first);
      indegree[p.first]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int course = q.front();
        q.pop();
        ans.push_back(course);
        for (int p : adj[course]) {
          indegree[p]--;
          if (indegree[p] == 0) q.push(p);
        }
      }
    }
    if (ans.size() == n) return ans;
    return {};
  }
};


int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
      int from = 0, to = 0;
      cin >> from >> to;
      edges[i].first = from;
      edges[i].second = to;
    }

    auto ans = Solution1().FindOrder(n, edges);
    for (int o : ans) {
      cout << o << " ";
    }
    cout << endl;

    ans = Solution2().FindOrder(n, edges);
    for (int o : ans) {
      cout << o << " ";
    }
    cout << endl;

    ans = Solution3().FindOrder(n, edges);
    for (int o : ans) {
      cout << o << " ";
    }
    cout << endl;

    ans = Solution4().FindOrder(n, edges);
    for (int o : ans) {
      cout << o << " ";
    }
    cout << endl;
  }
  return 0;
}
