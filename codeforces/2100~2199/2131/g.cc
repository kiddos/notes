#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;

vector<i64> p(32, 1);
void precompute() {
  i64 prod = 1;
  for (int i = 2; i < 32; ++i) {
    p[i] = (prod * i) % MOD;
    prod *= p[i];
    prod %= MOD;
  }
}

void remove_from_set(i64& k, int x, i64& ans) {
  if (k == 0) {
    return;
  }

  // remove x
  // this would create 1,2,3,...,x-1
  k--;
  ans *= x;
  ans %= MOD;
  for (int y = 1; y <= min(x-1, 30); ++y) {
    i64 r = 1LL << (y-1);
    if (r <= k) {
      k -= r;
      ans *= p[y];
      ans %= MOD;
    } else {
      remove_from_set(k, y, ans);
    }
  }
}

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  sort(s.begin(), s.end());

  i64 ans = 1;
  for (int i = 0; i < n; ++i) {
    i64 r = (1LL << (s[i]-1));
    if (s[i] <= 30 && r <= k) {
      k -= r;
      ans *= p[s[i]];
      ans %= MOD;
    } else {
      remove_from_set(k, s[i], ans);
      break;
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
