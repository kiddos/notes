#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

unordered_map<int,int> get_prime_factors(int x) {
  unordered_map<int, int> f;
  for (int d = 2; d*d <= x; ++d) {
    while (x % d == 0) {
      f[d]++;
      x /= d;
    }
  }
  if (x > 1) {
    f[x]++;
  }
  return f;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = 1;
  set<vector<int>> s;
  for (int i = 0; i < n; ++i) {
    unordered_map<int, int> f = get_prime_factors(a[i]);
    vector<int> primes;
    for (auto [p, c] : f) {
      if (c % 2 == 1) {
        primes.push_back(p);
      }
    }
    sort(primes.begin(), primes.end());

    // cout << a[i] << ": ";
    // for (int p : primes) {
    //   cout << p << " ";
    // }
    // cout << endl;

    if (s.count(primes)) {
      ans++;
      s.clear();
    }
    s.insert(primes);
  }
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
