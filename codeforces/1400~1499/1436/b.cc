#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_SIZE = 2000;

vector<int> primes;
void precompute() {
  vector<bool> is_prime(MAX_SIZE+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p * p <= MAX_SIZE; ++p) {
    if (is_prime[p]) {
      for (int i = p * p; i <= MAX_SIZE; i += p)
        is_prime[i] = false;
    }
  }
  for (int p = 2; p <= MAX_SIZE; ++p) {
    if (is_prime[p]) {
      primes.push_back(p);
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;

  int prime = *lower_bound(primes.begin(), primes.end(), (n - 1) * 4);
  vector<int> row(n, 4);
  int left = prime - (n-1) * 4 - 1;
  row[0] = 1;
  for (int i = 1; i < n; ++i) {
    if (left) {
      left -= 2;
      row[i] += 2;
    }
  }
  for (int r = 0; r < n; ++r) {
    int offset = r;
    for (int i = 0; i < n; ++i) {
      cout << row[(i+offset)%n] << " ";
    }
    cout << endl;
  }
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
