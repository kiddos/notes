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
  string s;
  cin >> s;
  vector<int> top_right(n);
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0') {
      top_right[i] = i;
    }
  }
  vector<int> bot_left(n);
  for (int i = 0; i < n-1; ++i) {
    if (s[i] == '0') {
      bot_left[i] = n-i-1;
    }
  }
  vector<int> diag(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      diag[i] = 1;
    }
  }

  int m = n * 3;
  DisjointSet ds(m);
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0') {
      if (s[i-1] == '1') {
        ds.join(i, i-1 + 2 * n);
      }
      if (s[i-1] == '0') {
        ds.join(i, i-1);
      }
    }
  }
  for (int i = 0; i < n-1; ++i) {
    if (s[i] == '0') {
      if (s[i+1] == '1') {
        ds.join(i+n, i+1 + 2 * n);
      }
      if (s[i+1] == '0') {
        ds.join(i+n, i+1+n);
      }
    }
  }
  vector<i64> sizes(m);
  for (int i = 1; i < n; ++i) {
    int p = ds.find(i);
    sizes[p] += top_right[i];
  }
  for (int i = 0; i < n-1; ++i) {
    int p = ds.find(i + n);
    sizes[p] += bot_left[i];
  }
  for (int i = 0; i < n; ++i) {
    int p = ds.find(i + n * 2);
    sizes[p] += diag[i];
  }

  i64 ans = *max_element(sizes.begin(), sizes.end());
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
