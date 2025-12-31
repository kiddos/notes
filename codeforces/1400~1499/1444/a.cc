#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_prime_factors(int x) {
  vector<int> f;
  for (int d = 2; d * d <= x; ++d) {
    while (x % d == 0) {
      x /= d;
      f.push_back(d);
    }
  }
  if (x > 1) {
    f.push_back(x);
  }
  return f;
}

void solve() {
  i64 p = 0;
  int q = 0;
  cin >> p >> q;

  if (p % q != 0) {
    cout << p << endl;
    return;
  }

  vector<int> prime_factors = get_prime_factors(q);
  map<int,int> q_primes;
  for (int prime : prime_factors) {
    q_primes[prime]++;
  }

  map<int,int> p_primes;
  for (auto [prime, _] : q_primes) {
    i64 x = p;
    int prime_count = 0;
    while (x % prime == 0) {
      prime_count++;
      x /= prime;
    }
    p_primes[prime] = prime_count;
  }

  i64 ans = 0;
  for (auto [prime, q_count] : q_primes) {
    int p_count = p_primes[prime];
    int exp = p_count - (q_count - 1);
    i64 x = p;
    for (int t = 0; t < exp; ++t) {
      x /= prime;
    }
    ans = max(ans, x);
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
