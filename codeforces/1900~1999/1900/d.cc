#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 100000;
vector<vector<int>> divisors(MAX_N+1);

void precompute() {
  for (int i = 1; i <= MAX_N; ++i) {
    for (int j = i; j <= MAX_N; j += i) {
      divisors[j].push_back(i);
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  vector<i64> counts(MAX_N+1);
  vector<i64> divisor_count(MAX_N+1);
  for (int i = 0; i < n; ++i) {
    for (int d : divisors[a[i]]) {
      counts[d] += (n-i-1) * divisor_count[d];
      divisor_count[d]++;
    }
  }
  int max_val = a.back();
  i64 ans = 0;
  for (int d = max_val; d >= 1; --d) {
    for (int d2 = d*2; d2 <= max_val; d2 += d) {
      counts[d] -= counts[d2];
    }
    ans += counts[d] * d;
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
