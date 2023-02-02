#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int max_val = 1e9;
  int k = sqrt(max_val);
  vector<bool> is_prime(k, true);
  for (int i = 2; i <= k; ++i) if (is_prime[i]) {
    for (int j = i+i; j <= k; j += i) {
      is_prime[j] = false;
    }
  }
  vector<int> primes;
  for (int i = 2; i <= k; ++i) if (is_prime[i]) {
    primes.push_back(i);
  }
  int m = primes.size();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    unordered_set<int> seen_factors;
    bool ans = false;
    for (int i = 0; i < n; ++i) {
      unordered_set<int> factors;
      int num = a[i];
      for (int j = 0; j < m; ++j) {
        if (num % primes[j] == 0) {
          factors.insert(primes[j]);
          while (num % primes[j] == 0) {
            num /= primes[j];
          }
        }
      }
      if (num > 1) {
        factors.insert(num);
      }

      for (int f : factors) {
        if (seen_factors.count(f)) {
          ans = true;
          break;
        } else {
          seen_factors.insert(f);
        }
      }

      if (ans) break;
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
