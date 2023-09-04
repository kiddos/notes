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
  int n = 0, q = 0;
  cin >> n >> q;

  FenwickTree row_tree(n+1), col_tree(n+1);
  vector<int> row(n+1), col(n+1);
  for (int i = 0; i < q; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int x = 0, y = 0;
      cin >> x >> y;
      if (++row[x] == 1) row_tree.update(x, 1);
      if (++col[y] == 1) col_tree.update(y, 1);
    } else if (t == 2) {
      int x = 0, y = 0;
      cin >> x >> y;
      if (--row[x] == 0) row_tree.update(x, -1);
      if (--col[y] == 0) col_tree.update(y, -1);
    } else if (t == 3) {
      int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
      cin >> x1 >> y1 >> x2 >> y2;
      int r = row_tree.get(x2) - row_tree.get(x1-1);
      int c = col_tree.get(y2) - col_tree.get(y1-1);
      int h = x2 - x1 + 1;
      int w = y2 - y1 + 1;
      if (r == h || c == w) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
