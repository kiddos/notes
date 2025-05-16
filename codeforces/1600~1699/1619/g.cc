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
  string empty;
  getline(cin, empty);
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> x(n), y(n), timer(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> timer[i];
  }

  map<int, vector<pair<int,int>>> same_x, same_y;
  for (int i = 0; i < n; ++i) {
    same_x[x[i]].push_back({y[i], i});
    same_y[y[i]].push_back({x[i], i});
  }

  DisjointSet ds(n);
  for (auto [xi, ys] : same_x) {
    sort(ys.begin(), ys.end());
    int i = 0;
    int size = ys.size();
    while (i < size) {
      int j = i;
      while (j+1 < size && ys[j+1].first - ys[j].first <= k) {
        ds.join(ys[j+1].second, ys[j].second);
        j++;
      }
      i = j+1;
    }
  }

  for (auto [yi, xs] : same_y) {
    sort(xs.begin(), xs.end());
    int i = 0;
    int size = xs.size();
    while (i < size) {
      int j = i;
      while (j+1 < size && xs[j+1].first - xs[j].first <= k) {
        ds.join(xs[j+1].second, xs[j].second);
        j++;
      }
      i = j+1;
    }
  }

  vector<int> min_time(n, numeric_limits<int>::max());
  for (int i = 0; i < n; ++i) {
    int p = ds.find(i);
    min_time[p] = min(min_time[p], timer[i]);
  }
  vector<int> explode;
  for (int i = 0; i < n; ++i) {
    if (min_time[i] < numeric_limits<int>::max()) {
      explode.push_back(min_time[i]);
    }
  }

  sort(explode.begin(), explode.end());
  // for (int e : explode) {
  //   cout << e << " ";
  // }
  // cout << endl;

  int ans = explode.back();
  int size = explode.size();
  for (int t = 0, i = size-1; i >= 1; --i, ++t) {
    int by_timer = explode[i-1];
    int by_polycarp = t;
    ans = min(ans, max(by_timer, by_polycarp));
  }
  ans = min(ans, size-1);
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
