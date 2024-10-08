#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int MAX_N = 100;

void solve() {
  vector<bool> is_prime(MAX_N+1, true);
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      for (int j = i+i; j <= MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i <= MAX_N; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  vector<int> next_prime(MAX_N);
  for (int i = 1; i < (int)primes.size(); ++i) {
    int p1 = primes[i-1], p2 = primes[i];
    next_prime[p1] = p2;
  }

  int n = 0, m = 0;
  cin >> n >> m;
  if (next_prime[n] == m) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
