#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;
constexpr int MOD = 1e9 + 7;

template<size_t N>
constexpr array<i64, N+1> create_factorial() {
  array<i64, N+1> result{};
  result[0] = 1;
  for (size_t i = 1; i <= N; ++i) {
    result[i] = result[i - 1] * i;
    result[i] %= MOD;
  }
  return result;
};

const array<i64, MAX_N+1> f = create_factorial<MAX_N>();

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int all_and = ~0;
  for (int i = 0; i < n; ++i) {
    all_and = all_and & a[i];
  }
  i64 all_and_count = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == all_and) {
      all_and_count++;
    }
  }
  i64 ans = (all_and_count * (all_and_count-1)) % MOD;
  ans *= f[n-2];
  ans %= MOD;
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
