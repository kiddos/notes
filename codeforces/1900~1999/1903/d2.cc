#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_BIT = 20;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int m = 1<<MAX_BIT;
  vector<int> counts(m+1);
  vector<vector<i64>> sums(m+1, vector<i64>(MAX_BIT));
  for (int i = 0; i < n; ++i) {
    counts[a[i]]++;

    i64 sum = 0;
    for (int b = 0; b < MAX_BIT; ++b) {
      sum += a[i] & (1LL <<b);
      sums[a[i]][b] += sum;
    }
  }

  for (int b = 0; b < MAX_BIT; ++b) {
    for (int mask = 0; mask < m; ++mask) {
      if (!(mask & (1<<b))) {
        counts[mask] += counts[mask | (1<<b)];
      }
    }
  }

  for (int b = 0; b < MAX_BIT; ++b) {
    for (int mask = 0; mask < m; ++mask) {
      if (!(mask & (1<<b))) {
        for (int b2 = 0; b2 < MAX_BIT; ++b2) {
          sums[mask][b2] += sums[mask | (1<<b)][b2];
        }
      }
    }
  }

  i64 S = 0;
  for (int i = 0; i < n; ++i) {
    S += (1LL << MAX_BIT) - a[i];
  }

  auto compute_query = [&](i64 k) -> i64 {
    if (k >= S) {
      return (1LL << MAX_BIT) + (k - S) / n;
    }

    i64 ans = 0;
    for (int b = MAX_BIT-1; b >= 0; --b) {
      i64 mask = 1LL << b;
      i64 x = (n - counts[ans | mask]) * mask;
      x -= sums[ans][b] - sums[ans | mask][b];
      if (k >= x) {
        k -= x;
        ans |= mask;
      }
    }
    return ans;
  };

  for (int i = 0; i < q; ++i) {
    i64 k = 0;
    cin >> k;
    cout << compute_query(k) << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
