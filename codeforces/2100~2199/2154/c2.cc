#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_prime_factor(int x) {
  vector<int> f;
  for (int d = 2; d*d <= x; ++d) {
    if (x % d == 0) {
      f.push_back(d);
      while (x % d == 0) {
        x /= d;
      }
    }
  }
  if (x > 1) {
    f.push_back(x);
  }
  return f;
}

constexpr int MAX_A = 200010;
vector<vector<int>> factors(MAX_A+1);

void precompute() {
  for (int i = 2; i <= MAX_A; ++i) {
    factors[i] = get_prime_factor(i);
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  map<int,int> prime_factor_count;
  for (int i = 0; i < n; ++i) {
    for (int f : factors[a[i]]) {
      prime_factor_count[f]++;
    }
  }

  for (auto [p, c] : prime_factor_count) {
    if (c > 1) {
      cout << "0" << endl;
      return;
    }
  }

  vector<i64> b2 = b;
  sort(b2.begin(), b2.end());
  i64 smallest = b2[0];
  i64 second_smallest = b2[1];
  i64 ans = smallest + second_smallest;

  for (int i = 0; i < n; ++i) {
    for (int f : factors[a[i]]) {
      prime_factor_count[f]--;
    }

    for (int f : factors[a[i]+1]) {
      if (prime_factor_count.count(f) && prime_factor_count[f] > 0) {
        ans = min(ans, b[i]);
        break;
      }
    }

    for (int f : factors[a[i]]) {
      prime_factor_count[f]++;
    }
  }

  set<int> primes;
  for (int i = 0; i < n; ++i) {
    if (b[i] == smallest) {
      continue;
    }

    for (int f : factors[a[i]]) {
      primes.insert(f);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (b[i] == smallest) {
      for (int p : primes) {
        i64 op = p - (a[i] % p);
        op %= p;
        ans = min(ans, b[i] * op);
      }
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
