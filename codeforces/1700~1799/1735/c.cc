#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n) {
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
    parent_[py] = px;
  }

 private:
  vector<int> parent_;
};

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  set<int> pool;
  for (int c = 0; c < 26; ++c) pool.insert(c);

  DisjointSet ds(26);
  vector<int> parent(26);
  iota(parent.begin(), parent.end(), 0);
  string ans;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    int p = parent[c];
    if (p == c) {
      if (pool.size() == 1) {
        ds.join(*pool.begin(), c);
        parent[c] = *pool.begin();
        pool.erase(pool.begin());
      } else {
        for (auto it = pool.begin(); it != pool.end(); ++it) {
          if (ds.find(*it) != ds.find(c)) {
            ds.join(*it, c);
            parent[c] = *it;
            pool.erase(it);
            break;
          }
        }
      }
    }
    ans.push_back(parent[c] + 'a');
  }
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
