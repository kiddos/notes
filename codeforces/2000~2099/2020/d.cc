#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parents_(n), rank_(n) {
    iota(parents_.begin(), parents_.end(), 0);
  }

  int find(int x) {
    if (parents_[x] != x) {
      parents_[x] = find(parents_[x]);
    }
    return parents_[x];
  }

  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
      return;
    }
    if (rank_[px] > rank_[py]) {
      parents_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parents_[px] = py;
    } else {
      parents_[py] = px;
      rank_[px]++;
    }
  }

  bool is_root(int x) {
    int px = find(x);
    return x == px;
  }

 private:
  vector<int> parents_, rank_;
};

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  
  vector<vector<vector<pair<int,int>>>> intervals(11);
  for (int d = 1; d <= 10; ++d) {
    intervals[d] = vector<vector<pair<int,int>>>(d);
  }
  for (int i = 0; i < m; ++i) {
    int a = 0, d = 0, k = 0;
    cin >> a >> d >> k;
    intervals[d][a % d].emplace_back(a, a + k * d);
  }

  for (int d = 1; d <= 10; ++d) {
    for (int s = 0; s < d; ++s) {
      vector<pair<int,int>>& i = intervals[d][s];
      sort(i.begin(), i.end());
      vector<pair<int,int>> merged;
      for (auto& [l, r] : i) {
        if (!merged.empty() && max(merged.back().first, l) <= min(merged.back().second, r)) {
          merged.back().first = min(merged.back().first, l);
          merged.back().second = max(merged.back().second, r);
        } else {
          merged.push_back({l, r});
        }
      }

      intervals[d][s] = merged;
    }
  }

  DisjointSet ds(n+1);
  for (int d = 1; d <= 10; ++d) {
    for (int s = 0; s < d; ++s) {
      for (auto& [l, r] : intervals[d][s]) {
        for (int a = l, b = l + d; b <= r; b += d) {
          ds.join(a, b);
        }
      }
    }
  }

  set<int> ps;
  for (int i = 1; i <= n; ++i) {
    int p = ds.find(i);
    // cout << i << " -> " << p << endl;
    ps.insert(p);
  }
  cout << ps.size() << endl;
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
