#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_K = 100000;
constexpr int MAX_A = 100000;
vector<vector<int>> factors(MAX_K+1);
vector<vector<int>> indices(MAX_A+1);

void precompute() {
  for (int x = 1; x <= MAX_K; ++x) {
    vector<int> f;
    for (int d = 1; d*d <= x; ++d) {
      if (x % d == 0) {
        f.push_back(d);
        f.push_back(x / d);
      }
    }
    sort(f.begin(), f.end());
    f.resize(unique(f.begin(), f.end()) - f.begin());
    factors[x] = f;
  }
}

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int max_a = *max_element(a.begin(), a.end());
  for (int i = 1; i <= n; ++i) {
    indices[a[i]].push_back(i);
  }

  vector<array<int,3>> queries;
  for (int i = 0; i < q; ++i) {
    int k = 0, l = 0, r = 0;
    cin >> k >> l >> r;
    queries.push_back({k, l, r});
  }

  for (auto [k, l, r] : queries) {
    vector<int> factor_indices;
    for (int f : factors[k]) {
      if (f > max_a || indices[f].empty()) {
        continue;
      }
      auto it = lower_bound(indices[f].begin(), indices[f].end(), l);
      if (it != indices[f].end() && *it <= r) {
        factor_indices.push_back(*it);
      }
    }
    sort(factor_indices.begin(), factor_indices.end());
    factor_indices.push_back(n+1);
    int p = l;
    i64 total = 0;
    for (int idx : factor_indices) {
      if (idx <= r) {
        total += (i64)(idx - p) * k;
        while (k % a[idx] == 0) {
          k /= a[idx];
        }
        p = idx;
      } else {
        total += (i64)(r - p + 1) * k;
        break;
      }
    }
    cout << total << endl;
  }

  for (int i = 1; i <= n; ++i) {
    indices[a[i]].clear();
  }
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
