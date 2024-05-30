#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n) {}

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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  set<int> s;
  for (int i = 0; i < n; ++i) {
    s.insert(a[i]);
    s.insert(a[i]-1);
  }
  map<int,int> indices;
  int idx = 1;
  for (int val : s) {
    indices[val] = idx++;
  }

  int m = indices.size();
  FenwickTree tree(m+1);
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int larger = tree.get(m) - tree.get(indices[a[i]]);
    int smaller = tree.get(indices[a[i]-1]);
    ans += min(larger, smaller);
    tree.update(indices[a[i]], 1);
  }
  cout << ans << endl;
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
