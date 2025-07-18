#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (x != parent_[x]) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
    } else {
      parent_[py] = px;
      rank_[px]++;
    }
  }

 private:
  vector<int> parent_, rank_;
};

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  int size = (n+1) * m;
  DisjointSet ds(size);
  vector<int> max_r(size);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      max_r[i * m + j] = i;
    }
  }

  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     cout << max_r[ds.find(i * m + j)] << " ";
  //   }
  //   cout << endl;
  // }

  auto find_max_r = [&](int r, int c) -> int {
    int x = r * m + c;
    int px = ds.find(x);
    return max_r[px];
  };

  auto join_top_cell = [&](int r, int c) {
    if (r-1 < 0) {
      return;
    }
    if (a[r-1][c] != 2) {
      return;
    }
    int x = (r-1) * m + c;
    int px = ds.find(x);
    int y = r * m + c;
    int py = ds.find(y);

    ds.join(x, y);
    int new_max = max(max_r[px], max_r[py]);
    max_r[px] = max_r[py] = new_max;
  };

  auto simulate = [&](int c) -> int {
    int r = 0;
    while (r < n) {
      if (a[r][c] == 1) {
        a[r][c] = 2;
        join_top_cell(r, c);
        c++;
      } else if (a[r][c] == 3) {
        a[r][c] = 2;
        join_top_cell(r, c);
        c--;
      } else {
        int can_reach = find_max_r(r, c);
        r = can_reach + 1;
        if (r <= n) {
          join_top_cell(r, c);
        }
      }
    }
    return c;
  };

  vector<int> c(k);
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
  }

  vector<int> ans;
  for (int i = 0; i < k; ++i) {
    int final_c = simulate(c[i]-1);
    ans.push_back(final_c+1);
  }

  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     cout << max_r[ds.find(i * m + j)] << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < k; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
