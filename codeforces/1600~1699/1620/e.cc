#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n) {
    for (int i = 0; i < n; ++i) {
      parent_[i].first = i;
    }
  }

  pair<int,int> find(int x, int t) {
    if (x != parent_[x].first && t < parent_[x].second) {
      parent_[x] = find(parent_[x].first, parent_[x].second);
    }
    return parent_[x];
  }

  void join(int x, int y, int t) {
    auto py = find(y, t);
    parent_[x] = py;
  }

 private:
  vector<pair<int,int>> parent_;
};

constexpr int MAX_X = 500000;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int,3>> queries;
  for (int i = 0; i < n; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int x = 0;
      cin >> x;
      queries.push_back({type, x, 0});
    } else if (type == 2) {
      int x = 0, y = 0;
      cin >> x >> y;
      queries.push_back({type, x, y});
    }
  }

  vector<int> ans;
  DisjointSet ds(MAX_X+1);
  for (int i = n-1; i >= 0; --i) {
    auto [type, x, y] = queries[i];
    int t = i + 1;
    if (type == 2) {
      ds.join(x, y, t);
    } else {
      int parent = ds.find(x, t).first;
      ans.push_back(parent);
    }
  }
  reverse(ans.begin(), ans.end());
  for (int a : ans) {
    cout << a << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
} 
