#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
  ll n = 0, m = 0;
  int k = 0;
  cin >> n >> m >> k;
  vector<int> a(k);
  for (int i = 0; i < k; ++i) cin >> a[i];

  FenwickTree tree(k);
  vector<int> smaller(k);
  for (int i = 0; i < k; ++i) {
    smaller[i] = tree.get(a[i]);
    tree.update(a[i], 1);
  }
  
  // for (int i= 0; i < k; ++i) {
  //   cout << smaller[i] << " ";
  // }
  // cout << endl;

  ll max_size = n * m - 3;
  for (int i = 0; i < k; ++i) {
    if (smaller[i] >= max_size) {
      cout << "TIDAK" << endl;
      return;
    }
  }
  cout << "YA" << endl;
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
