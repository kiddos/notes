#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, c = 0;
  cin >> n >> c;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<pair<i64,int>> pool;
  for (int i = 2; i <= n; ++i) {
    pool.emplace_back(a[i] / c - i, i);
  }
  sort(pool.rbegin(), pool.rend());

  i64 sum = a[1];
  while (!pool.empty()) {
    vector<pair<i64,int>> new_pool;
    for (auto [weight, idx] : pool) {
      if (sum + a[idx] >= (i64)c * idx) {
        sum += a[idx];
      } else {
        new_pool.emplace_back(weight, idx);
      }
    }

    if (new_pool.size() == pool.size()) {
      cout << "NO" << endl;
      return;
    }
    pool = std::move(new_pool);
  }
  cout << "YES" << endl;
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
