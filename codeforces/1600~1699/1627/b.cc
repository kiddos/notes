#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, int m) {
  vector<vector<int>> visited(n, vector<int>(m));
  int dist = n-1 + m-1;
  queue<pair<int, int>> q;
  vector<pair<int,int>> start = {{0, 0}, {0, m-1}, {n-1, 0}, {n-1, m-1}};
  for (pair<int, int>& s : start) {
    if (!visited[s.first][s.second]) {
      q.push(s);
      visited[s.first][s.second] = true;
    }
  }

  vector<vector<int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector<int> ans;
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();
      ans.push_back(dist);
      for (vector<int>& d : delta) {
        int r2 = r + d[0], c2 = c + d[1];
        if (r2 >= 0 && c2 >= 0 && r2 < n && c2 < m && !visited[r2][c2]) {
          visited[r2][c2] = true;
          q.push({r2, c2});
        }
      }
    }
    dist--;
  }

  reverse(ans.begin(), ans.end());
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> ans = solve(n, m);
    for (int a : ans) cout << a << " ";
    cout << '\n';
  }
  cout << flush;
  return 0;
}
