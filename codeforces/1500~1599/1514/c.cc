#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_prime_factor(int x) {
  vector<int> factors;
  for (int d = 2; d*d <= x; ++d) {
    if (x % d == 0) {
      while (x % d == 0) {
        x /= d;
      }
      factors.push_back(d);
    }
  }
  if (x > 1) {
    factors.push_back(x);
  }
  return factors;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> n_factors = get_prime_factor(n);
  set<int> s(n_factors.begin(), n_factors.end());

  auto should_skip = [&](int x) -> bool {
    vector<int> factors = get_prime_factor(x);
    for (int f : factors) {
      if (s.count(f)) {
        return true;
      }
    }
    return false;
  };

  set<int> ans;
  i64 p = 1;
  for (int i = 1; i < n; ++i) {
    if (should_skip(i)) {
      continue;
    }
    p *= i;
    p %= n;
    ans.insert(i);
  }

  if (p != 1) {
    ans.erase(p);
  }
  cout << ans.size() << endl;
  for (int f : ans) {
    cout << f << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
