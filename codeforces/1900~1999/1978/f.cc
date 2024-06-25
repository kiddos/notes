#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

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

constexpr int MAX_N = 1000000;
vector<int> primes;

void precompute() {
  vector<bool> is_primes(MAX_N+1, true);
  is_primes[0] = is_primes[1] = false;
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_primes[i]) {
      for (int j = i+i; j <= MAX_N; j += i) {
        is_primes[j] = false;
      }
    }
  }
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_primes[i]) {
      primes.push_back(i);
    }
  }
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> diag, diag_sizes;
  for (int i = 1; i < n; ++i) {
    diag.push_back(a[i]);
    diag_sizes.push_back(i);
  }
  for (int i = 0, s = n; i < n; ++i, --s) {
    diag.push_back(a[i]);
    diag_sizes.push_back(s);
  }

  map<int, vector<int>> indices;
  int m = diag.size();
  for (int i = 0; i < m; ++i) {
    int x = diag[i];
    for (int p : primes) {
      if (p * p > x) break;
      if (x % p == 0) {
        while (x % p == 0) {
          x /= p;
        }
        indices[p].push_back(i);
      }
    }
    if (x > 1) {
      indices[x].push_back(i);
    }
  }

  DisjointSet ds(m);
  for (auto& [prime, l] : indices) {
    for (int i = 0, j = 0; i < (int)l.size(); ++i) {
      while (j < (int)l.size() && l[j] - l[i] <= k) {
        ds.join(l[i], l[j]);
        // cout << "join " << l[i] << "," << l[j] << endl;
        j++;
      }
    }
  }

  vector<bool> added(m);
  i64 ans = 0;
  for (int i = 0; i < m; ++i) {
    if (diag[i] == 1) {
      ans += diag_sizes[i];
    } else {
      int p = ds.find(i);
      if (!added[p]) {
        added[p] = true;
        ans++;
      }
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
