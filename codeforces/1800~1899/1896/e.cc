#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n+1) {}

  int get(int i) {
    int total = 0;
    while (i > 0) {
      total += data_[i];
      i -= (i & -i);
    }
    return total;
  }

  void update(int i, int x) {
    int n = data_.size();
    while (i < n) {
      data_[i] += x;
      i += (i & -i);
    }
  }

 private:
  vector<int> data_;
};

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];


  FenwickTree tree(2*n+1);
  vector<int> b(n*2+1);
  for (int i = 1; i <= n; ++i) {
    b[i] = a[i];
  }
  for (int i = n+1; i <= 2*n; ++i) {
    b[i] = a[i-n] + n;
  }

  vector<int> ans(2*n+1);
  for (int i = 2*n; i >= 1; --i) {
    int r = b[i];
    if (r < i) r += n;
    if (i <= n) {
      ans[b[i]] = r - i - (tree.get(r) - tree.get(i));
    }
    tree.update(r, 1);
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
