#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 19 * (2^2 + 2^3) + 14 * (2 ^ 1) + 9 * (2 ^ 0)

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  constexpr int MOD = 998244353;
  vector<i64> p2 = {1};
  for (int i = 0; i <= n; ++i) {
    p2.push_back((p2.back() * 2) % MOD);
  }

  vector<int> max_vals(n+1);
  for (int i = 1; i <= n; ++i) {
    int max_val = a[i];
    for (int j = i+i; j <= n; j += i) {
      max_val = max(max_val, a[j]);
    }
    max_vals[i] = max_val;
  }

  map<int,int> counts;
  for (int i = 1; i <= n; ++i) counts[max_vals[i]]++;

  for (auto it = next(counts.begin()); it != counts.end(); ++it) {
    auto p = prev(it);
    it->second += p->second;
  }

  i64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    counts[max_vals[i]]--;
    ans += max_vals[i] * p2[counts[max_vals[i]]];
    ans %= MOD;
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
