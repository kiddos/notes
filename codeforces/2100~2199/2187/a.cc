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
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int min_idx = min_element(a.begin(), a.end()) - a.begin();
  int max_idx = max_element(a.begin(), a.end()) - a.begin();
  auto possible = [&](i64 k) -> bool {
    DisjointSet ds(n);
    for (int i = 0; i < n; ++i) {
      if (abs(a[i] - a[min_idx]) >= k) {
        ds.join(min_idx, i);
      }
      if (abs(a[i] - a[max_idx]) >= k) {
        ds.join(max_idx, i);
      }
    }

    vector<vector<int>> group(n+1);
    for (int i = 0; i < n; ++i) {
      int p = ds.find(i);
      group[p].push_back(i);
    }
    vector<int> b(n);
    for (int p = 0; p < n; ++p) {
      vector<int> vals;
      for (int idx : group[p]) {
        vals.push_back(a[idx]);
      }
      sort(vals.begin(), vals.end());
      for (int j = 0; j < (int)group[p].size(); ++j) {
        int idx = group[p][j];
        b[idx] = vals[j];
      }
    }
    for (int i = 1; i < n; ++i) {
      if (b[i-1] > b[i]) {
        return false;
      }
    }
    return true;
  };

  i64 l = 0, r = 2e9;
  i64 ans = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      l = mid+1;
      ans = mid;
    } else {
      r = mid-1;
    }
  }

  if (ans >= 2e9) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
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
