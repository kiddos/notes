#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n+1) {}

  void update(int i, int x) {
    int n = data_.size();
    while (i < n) {
      data_[i] += x;
      i += (i & -i);
    }
  }

  int get(int i) {
    int total = 0;
    while (i > 0) {
      total += data_[i];
      i -= (i & -i);
    }
    return total;
  }

 private:
  vector<int> data_;
};

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;

  vector<string> matrix(n);
  for (int i = 0; i < n; ++i) cin >> matrix[i];

  auto index = [&](int i, int j) {
    return j * n + i + 1;
  };

  FenwickTree tree(m*n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (matrix[i][j] == '*') {
        int p = index(i, j);
        tree.update(p, 1);
      }
    }
  }

  while (q-- > 0) {
    int x = 0, y = 0;
    cin >> x >> y;
    x--;
    y--;
    int p = index(x, y);

    if (matrix[x][y] == '*') {
      tree.update(p, -1);

      matrix[x][y] = '.';
    } else if (matrix[x][y] == '.') {
      tree.update(p, 1);

      matrix[x][y] = '*';
    }

    int total = tree.get(m*n);
    int prefix = tree.get(total);
    int ans = total - prefix;
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
