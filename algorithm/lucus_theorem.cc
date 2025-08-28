#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// when we want to compute pascal's triangle at nth row % mod
// where the mod is small
// we can use lucas theorem

constexpr int MOD = 10;
vector<int> f(MOD, 1);

void precompute() {
  for (int i = 2; i < MOD; ++i) {
    f[i] = f[i - 1] * i;
  }
}

int C(int n, int k, int mod) {
  int ans = 1;
  while (n > 0 || k > 0) {
    int coef_n = n % mod;
    int coef_k = k % mod;
    int c = coef_n >= coef_k ? f[coef_n] / f[coef_n - coef_k] / f[coef_k] : 0;
    ans *= c;
    ans %= mod;
    n /= mod;
    k /= mod;
  }
  return ans;
}

int C10(int n, int k) {
  int r2 = C(n, k, 2);
  int r5 = C(n, k, 5);
  for (int r = 0; r < 10; ++r) {
    if (r % 2 == r2 && r % 5 == r5) {
      return r;
    }
  }
  assert(false);
  return -1;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> row(n);
  for (int i = 0; i < n; ++i) {
    row[i] = C10(n-1, i);
  }

  for (int i = 0; i < n; ++i) {
    cout << row[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  solve();
  return 0;
}
