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
    if (px == py) {
      return;
    }

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
  vector<int> p(n+1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
  }
  int m = 0;
  cin >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  vector<bool> has_dam(n+1);
  for (int i = 0; i < m; ++i) {
    has_dam[a[i]] = true;
  }

  DisjointSet ds(n+1);
  vector<int> ans;
  for (int i = 2; i <= n; ++i) {
    int p1 = ds.find(i);
    int p2 = ds.find(p[i]);
    if (has_dam[p1] && has_dam[p2]) {
      ans.push_back(i);
    }
    ds.join(i, p[i]);
    int p3 = ds.find(i);
    has_dam[p3] = has_dam[p1] || has_dam[p2];
  }

  cout << ans.size() << " ";
  for (int edge : ans) {
    cout << edge << " ";
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
