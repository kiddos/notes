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
  int n = 0, q = 0;
  cin >> n >> q;

  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<vector<pair<int,int>>> queries(n+1);
  for (int j = 0; j < q; ++j) {
    int i = 0, x = 0;
    cin >> i >> x;
    queries[x].emplace_back(i, j);
  }
  for (int k = 1; k <= n; ++k) {
    vector<pair<int,int>>& indices = queries[k];
    sort(indices.rbegin(), indices.rend());
  }

  constexpr int MAX_A = 200000;
  vector<vector<int>> indices(MAX_A + 1);
  for (int i = 1; i <= n; ++i) {
    indices[a[i]].push_back(i);
  }

  auto find_monster_with_level = [&](FenwickTree& tree, int start, int count) -> int {
    int l = start, r = n;
    int ans = n + 1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int seen = tree.get(mid) - tree.get(start-1);
      if (seen >= count) {
        ans = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    return ans;
  };

  vector<int> k_index(n+1);
  int level = 1;
  vector<bool> ans(q);
  FenwickTree tree(n+1);
  for (int i = 1; i <= n; ++i) {
    tree.update(i, 1);
  }
  while (level <= n) {
    for (int k = 1; k <= n; ++k) {
      if (k_index[k] > n) {
        break;
      }
      // cout << k << ", start = " << start_idx << endl;
      int end_idx = find_monster_with_level(tree, k_index[k], k);
      while (!queries[k].empty() && queries[k].back().first <= end_idx) {
        auto [idx, qi] = queries[k].back();
        queries[k].pop_back();
        if (a[idx] >= level) {
          ans[qi] = true;
        }
      }

      k_index[k] = end_idx+1;
    }
    // cout << "level=" << level << endl;

    for (int j : indices[level]) {
      tree.update(j, -1);
    }
    level++;
  }

  for (int i = 0; i < q; ++i) {
    if (ans[i]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
