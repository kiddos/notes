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

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  map<int,int> prime_factor_count;
  for (int i = 0; i < n; ++i) {
    vector<int> factors = get_prime_factor(a[i]);
    for (int f : factors) {
      prime_factor_count[f]++;
    }
  }

  for (auto [p, c] : prime_factor_count) {
    if (c > 1) {
      cout << "0" << endl;
      return;
    }
  }

  for (int i = 0; i < n; ++i) {
    vector<int> factors = get_prime_factor(a[i]);
    for (int f : factors) {
      prime_factor_count[f]--;
    }

    vector<int> new_factors = get_prime_factor(a[i]+1);
    for (int f : new_factors) {
      if (prime_factor_count.count(f) && prime_factor_count[f] > 0) {
        cout << "1" << endl;
        return;
      }
    }

    for (int f : factors) {
      prime_factor_count[f]++;
    }
  }

  cout << "2" << endl;
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
