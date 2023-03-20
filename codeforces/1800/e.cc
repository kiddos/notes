#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), rank_(n) {
    iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (parent_[x] != x) {
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
  int n = 0, k = 0;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;

  auto sort_str = [&](const string& s) -> string {
    DisjointSet ds(n);
    for (int i = 0; i < n; ++i) {
      if (i+k < n) ds.join(i, i+k);
      if (i+k+1 < n) ds.join(i, i+k+1);
    }
    vector<string> groups(n);
    for (int i = 0; i < n; ++i) {
      int p = ds.find(i);
      groups[p].push_back(s[i]);
    }
    for (string& g : groups) {
      sort(g.rbegin(), g.rend());
    }

    string s2;
    for (int i = 0; i < n; ++i) {
      int p = ds.find(i);
      s2.push_back(groups[p].back());
      groups[p].pop_back();
    }
    return s2;
  };

  string s2 = sort_str(s);
  string t2 = sort_str(t);
  // cout << s2 << ", " << t2 << endl;
  if (s2 == t2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
