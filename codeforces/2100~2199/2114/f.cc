#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 1000000;
vector<vector<int>> factors(MAX_N+1);

vector<int> get_prime_factors(int x) {
  vector<int> primes;
  for (int d = 2; d * d <= x; ++d) {
    while (x % d == 0) {
      primes.push_back(d);
      x /= d;
    }
  }
  if (x > 1) {
    primes.push_back(x);
  }
  return primes;
}

void precompute() {
  for (int i = 2; i <= MAX_N; ++i) {
    factors[i] = get_prime_factors(i);
  }
}

void solve() {
  int x = 0, y = 0, k = 0;
  cin >> x >> y >> k;
  vector<int>& px = factors[x];
  vector<int>& py = factors[y];
  map<int, int> f;
  for (int p : py) {
    f[p]++;
  }
  for (int p : px) {
    f[p]--;
  }
  vector<int> add, remove;
  for (auto [p, count] : f) {
    if (count > 0) {
      for (int i = 0; i < count; ++i) {
        add.push_back(p);
      }
    } else if (count < 0) {
      for (int i = 0; i < -count; ++i) {
        remove.push_back(p);
      }
    }
  }

  auto check_possible = [&](vector<int>& list) -> bool {
    for (int p : list) {
      if (p > k) {
        return false;
      }
    }
    return true;
  };

  // for (int p : add) {
  //   cout << p << " ";
  // }
  // cout << endl;
  // for (int p : remove) {
  //   cout << p << " ";
  // }
  // cout << endl;

  if (!check_possible(add) || !check_possible(remove)) {
    cout << "-1" << endl;
    return;
  }

  auto min_ops = [&](vector<int>& primes, int k) -> int {
    int n = primes.size();
    if (n == 0) {
      return 0;
    }
    int prod = 1;
    for (int p : primes) {
      prod *= p;
    }
    vector<int> factor;
    for (int d = 2; d * d <= prod; ++d) {
      if (prod % d == 0) {
        factor.push_back(d);
        if (prod / d != d) {
          factor.push_back(prod / d);
        }
      }
    }
    factor.push_back(prod);

    sort(factor.begin(), factor.end());
    int size = factor.size();
    vector<int> dp(size, size);
    for (int i = 0; i < size; ++i) {
      if (factor[i] <= k) {
        dp[i] = 1;
      }
    }

    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < i; ++j) {
        if (factor[i] % factor[j] == 0 && factor[i] / factor[j] <= k) {
          dp[i] = min(dp[i], dp[j]+1);
        }
      }
    }
    return dp.back();
  };

  int ans = min_ops(add, k) + min_ops(remove, k);
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
