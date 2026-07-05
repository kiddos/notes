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

  bool join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) {
      return false;
    }
    if (rank_[px] > rank_[py]) {
      parent_[py] = px;
    } else if (rank_[py] > rank_[px]) {
      parent_[px] = py;
    } else {
      parent_[py] = px;
      rank_[px]++;
    }
    return true;
  }

 private:
  vector<int> parent_, rank_;
};

void solve() {
  int n = 0;
  cin >> n;
  string s, t;
  cin >> s >> t;

  DisjointSet ds(26);
  vector<pair<char, char>> ans;
  for (int i = 0; i < n; ++i) {
    int c1 = s[i]-'a';
    int c2 = t[i]-'a';
    if (ds.join(c1, c2)) {
      ans.push_back({s[i], t[i]});
    }
  }

  cout << ans.size() << endl;
  for (auto [c1, c2] : ans) {
    cout << c1 << " " << c2 << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
