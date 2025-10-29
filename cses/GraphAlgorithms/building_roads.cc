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
  int n = 0, m = 0;
  cin >> n >> m;
  vector<pair<int,int>> roads;
  for (int i = 0; i < m; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    roads.emplace_back(a, b);
  }

  DisjointSet ds(n);
  for (auto [a, b] : roads) {
    ds.join(a, b);
  }

  vector<int> s;
  for (int i = 0; i < n; ++i) {
    int p = ds.find(i);
    s.push_back(p);
  }
  sort(s.begin(), s.end());
  s.resize(unique(s.begin(), s.end()) - s.begin());

  vector<pair<int,int>> ans;
  for (int i = 1; i < (int)s.size(); ++i) {
    ans.push_back({s[i-1]+1, s[i]+1});
  }

  cout << ans.size() << endl;
  for (auto [c, d] : ans) {
    cout << c << " " << d << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
