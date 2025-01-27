#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class FenwickTree {
 public:
  FenwickTree(int n) : data_(n) {}

  int query(int i) {
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


void answer(int x) {
  cout << "! " << x << endl;
};

void solve() {
  int n = 0, t = 0;
  cin >> n >> t;

  FenwickTree tree(n+1);

  map<int,int> sums;
  auto query = [&](int l, int r) -> int {
    if (sums.count(r)) {
      return r - sums[r] - tree.query(r);
    }
    cout << "? " << l << " " << r << endl;
    int sum = 0;
    cin >> sum;
    sums[r] = sum - tree.query(r);
    return r - sum;
  };

  for (int i = 0; i < t; ++i) {
    int k = 0;
    cin >> k;

    int l = 1, r = n;
    int idx = n;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int zeros = query(1, mid);
      if (zeros >= k) {
        r = mid-1;
        idx = mid;
      } else {
        l = mid+1;
      }
    }
    answer(idx);
    tree.update(idx, 1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
