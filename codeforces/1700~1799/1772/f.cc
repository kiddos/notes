#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<string> read_picture(int n) {
  vector<string> p;
  string line;
  getline(cin, line);
  for (int i = 0; i < n; ++i) {
    cin >> line;
    p.push_back(line);
  }
  return p;
}

bool can_invert_at(vector<string>& pic, int r, int c) {
  vector<vector<int>> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (auto d : delta) {
    int r2 = r + d[0], c2 = c + d[1];
    if (pic[r2][c2] == pic[r][c]) {
      return false;
    }
  }
  return true;
}

vector<pair<int,int>> diff_point(vector<string>& p1, vector<string>& p2, int n, int m) {
  vector<pair<int,int>> diff;
  for (int i = 1; i < n-1; ++i) {
    for (int j = 1; j < m-1; ++j) {
      if (p1[i][j] != p2[i][j]) {
        diff.emplace_back(i, j);
      }
    }
  }
  return diff;
}

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<vector<string>> pictures;

  for (int i = 0; i < k+1; ++i) {
    pictures.push_back(read_picture(n));
  }

  vector<pair<int,int>> can_invert;
  for (int i = 1; i < n-1; ++i) {
    for (int j = 1; j < m-1; ++j) {
      for (vector<string>& p : pictures) {
        if (can_invert_at(p, i, j)) {
          can_invert.emplace_back(i, j);
          break;
        }
      }
    }
  }

  int size = k+1;
  vector<unordered_set<int>> adj(size);

  for (auto [r, c] : can_invert) {
    vector<int> starts, ends;
    for (int idx = 0; idx < size; ++idx) {
      if (can_invert_at(pictures[idx], r, c)) {
        starts.push_back(idx);
      } else {
        ends.push_back(idx);
      }
    }
    for (int i2 : ends) {
      for (int i1 : starts) {
        adj[i2].insert(i1);
      }
    }
  }

  vector<int> order;
  vector<bool> visited(size);
  function<void(int)> dfs = [&](int node) {
    if (visited[node]) {
      return;
    }
    visited[node] = true;
    for (int next_node : adj[node]) {
      dfs(next_node);
    }
    order.push_back(node);
  };

  for (int i = 0; i < size; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  cout << order[0]+1 << endl;
  vector<array<int,3>> ans;
  for (int j = 1; j < size; ++j) {
    int i1 = order[j-1], i2 = order[j];
    auto diffs = diff_point(pictures[i1], pictures[i2], n, m);
    for (auto [r, c] : diffs) {
      ans.push_back({1, r+1, c+1});
    }
    ans.push_back({2, i2+1, 0});
  }

  cout << ans.size() << endl;
  for (auto a : ans) {
    if (a[0] == 1) {
      cout << "1 " << a[1] << " " << a[2] << endl;
    } else {
      cout << "2 " << a[1] << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
