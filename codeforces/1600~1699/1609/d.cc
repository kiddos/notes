#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : extra(0), parent_(n), rank_(n), size_(n, 1) {
    iota(parent_.begin(), parent_.end(), 0);
    for (int i = 0; i < n; ++i) {
      group_sizes_.insert(1);
    }
  }

  int find(int x) {
    if (parent_[x] != x) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
      extra++;
      return;
    }

    group_sizes_.erase(group_sizes_.find(size_[px]));
    group_sizes_.erase(group_sizes_.find(size_[py]));
    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
      size_[px] += size_[py];
      group_sizes_.insert(size_[px]);
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
      size_[py] += size_[px];
      group_sizes_.insert(size_[py]);
    } else {
      parent_[py] = px;
      size_[px] += size_[py];
      rank_[px]++;
      group_sizes_.insert(size_[px]);
    }
  }

  int get_answer() {
    int e = extra;
    int ans = 0;
    for (auto it = group_sizes_.rbegin(); it != group_sizes_.rend(); ++it) {
      ans += *it;
      if (e == 0) {
        break;
      }
      e--;
    }
    return ans;
  }

 private:
  int extra;
  vector<int> parent_, rank_, size_;
  multiset<int> group_sizes_;
};

void solve() {
  int n = 0, d = 0;
  cin >> n >> d;

  DisjointSet ds(n);
  for (int i = 0; i < d; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    x--;
    y--;
    ds.join(x, y);
    int ans = ds.get_answer() - 1;
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
