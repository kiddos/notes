#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;
vector<bool> is_prime(MAX_N + 1, true);

void precompute() {
  for (int i = 2; i * i <= MAX_N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

vector<int> get_factors(int x) {
  vector<int> f;
  for (int d = 2; d*d <= x; ++d) {
    if (x % d == 0) {
      f.push_back(d);
      f.push_back(x / d);
    }
  }
  sort(f.begin(), f.end());
  f.resize(unique(f.begin(), f.end()) - f.begin());
  return f;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> count(n+1), count0(n+1);
  for (int i = 0; i < n; ++i) {
    count0[a[i]]++;
  }
  i64 ans = 0;
  int primes = 0;
  for (int i = 0; i < n; ++i) {
    if (is_prime[a[i]]) {
      ans += primes - count[a[i]];
      primes++;
    } else {
      vector<int> f = get_factors(a[i]);
      if (f.size() == 1 && is_prime[f[0]]) {
        ans += count0[f[0]];
        ans += count[a[i]] +1;
      } else if (f.size() == 2 && is_prime[f[0]] && is_prime[f[1]]) {
        ans += count0[f[0]] + count0[f[1]];
        ans += count[a[i]]+1;
      }
    }
    count[a[i]]++;
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
