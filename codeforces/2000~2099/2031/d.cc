#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    for (int i = 0; i < n; ++i) parent_[i] = i;
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
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  DisjointSet ds(n);

  set<pair<int,int>> s;
  for (int i = 0; i < n; ++i) {
    if (!s.empty()) {
      auto largest = *s.rbegin();
      if (largest.first > a[i]) {
        ds.join(i, largest.second);
      }
    }

    pair<int,int> key = {a[i], i};
    s.insert(key);
  }

  s.clear();
  for (int i = n-1; i >= 0; --i) {
    auto it = s.upper_bound({a[i]-1, n});
    if (it != s.begin()) {
      auto largest = *(--it);
      ds.join(i, largest.second);
    }

    pair<int,int> key = {a[i], i};
    s.insert(key);
  }

  vector<int> ans(n);
  vector<vector<int>> group(n);
  for (int i = 0; i < n; ++i) {
    int p = ds.find(i);
    group[p].push_back(i);
  }

  for (vector<int>& indices : group) {
    int max_val = 0;
    for (int idx : indices) {
      max_val = max(max_val, a[idx]);
    }
    for (int idx : indices) {
      ans[idx] = max_val;
    }
  }

  for (int i = 0; i < n; ++i) {
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
