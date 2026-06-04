#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_prime_factors(int x) {
  vector<int> f;
  for (int d = 2; d * d <= x; ++d) {
    while (x % d == 0) {
      f.push_back(d);
      x /= d;
    }
  }
  if (x > 1) {
    f.push_back(x);
  }
  sort(f.begin(), f.end());
  f.resize(unique(f.begin(), f.end()) - f.begin());
  return f;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  vector<int> primes1 = get_prime_factors(a[0]);
  vector<int> primes2 = get_prime_factors(b[0]);
  
  auto is_wcd = [&](int p) -> bool {
    for (int i = 0; i < n; ++i) {
      if ((a[i] % p != 0) && (b[i] % p != 0)) {
        return false;
      }
    }
    return true;
  };

  for (int p : primes1) {
    if (is_wcd(p)) {
      cout << p << endl;
      return;
    }
  }
  for (int p : primes2) {
    if (is_wcd(p)) {
      cout << p << endl;
      return;
    }
  }
  cout << "-1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
